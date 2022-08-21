#!env swift

import Foundation

guard let name = CommandLine.arguments.dropFirst().first else {
    fatalError("Need name of binding")
}

let fullFileURL = URL(fileURLWithPath: FileManager.default.currentDirectoryPath).appendingPathComponent(#filePath)
let projectRoot = fullFileURL.deletingLastPathComponent().deletingLastPathComponent()
let sourcesRoot = projectRoot.appendingPathComponent("Sources")
let templateRoot = projectRoot.appendingPathComponent("Templates")
let templateBindingName = "TemplateBinding"
let templateBindingURL = templateRoot.appendingPathComponent(templateBindingName)

guard FileManager.default.fileExists(atPath: templateBindingURL.path) else {
    fatalError("\(templateBindingURL.path) does not exist!")
}

let targetBindingURL = sourcesRoot.appendingPathComponent(name)

if FileManager.default.fileExists(atPath: targetBindingURL.path) {
    guard CommandLine.arguments.contains("-f") || CommandLine.arguments.contains("--force") else {
        fatalError("\(targetBindingURL.path) already exists. Delete it or run again with --force at the end")
    }
    try FileManager.default.removeItem(at: targetBindingURL)
}

try FileManager.default.copyItem(at: templateBindingURL, to: targetBindingURL)

try FileManager.default.enumerator(at: targetBindingURL, includingPropertiesForKeys: [.isDirectoryKey])?.forEach { url in
    let url = url as! URL
    guard try url.resourceValues(forKeys: [.isDirectoryKey]).isDirectory == false else {
        return
    }
    var currentURL = url
    let pathExtension = currentURL.pathExtension
    if currentURL.deletingPathExtension().lastPathComponent == templateBindingName {
        // rename and string replace
        let newURL = url.deletingLastPathComponent().appendingPathComponent(name).appendingPathExtension(pathExtension)
        try FileManager.default.moveItem(at: url, to: newURL)
        currentURL = newURL
    }
    let string = try String(contentsOf: currentURL)
    let replaced = string.replacingOccurrences(of: templateBindingName, with: name)
    if replaced == string {
        return
    }
    try Data(replaced.utf8).write(to: currentURL)
}
