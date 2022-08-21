// swift-tools-version: 5.6
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

extension Target {
    static func privateFrameworkBinding(_ name: String, dependencies: [Dependency] = []) -> Target {
        .target(name: name, dependencies: dependencies, linkerSettings: [
            .unsafeFlags(["-F/System/Library/PrivateFrameworks"]),
            .linkedFramework(name)
        ])
    }
}

extension Product {
    static func privateFrameworkBinding(_ name: String) -> Product {
        .library(name: name, targets: [name])
    }
}

extension Package {
    static var privateFrameworksByPackageName: [String: [String]] = [:]
    
    func withPrivateFrameworkBinding(_ name: String, dependencies: [Target.Dependency] = []) -> Package {
        Package.privateFrameworksByPackageName[self.name, default: []].append(name)
        products.append(.privateFrameworkBinding(name))
        targets.append(.privateFrameworkBinding(name, dependencies: dependencies))
        return self
    }
    
    func withParisTarget() -> Package {
        targets.append(.executableTarget(name: "Paris", dependencies: Package.privateFrameworksByPackageName[self.name, default: []].map(Target.Dependency.init(stringLiteral:))))
        return self
    }
}

let package = Package(
    name: "Paris"
).withPrivateFrameworkBinding("IMCore", dependencies: ["IMSharedUtilities", "IMFoundation"])
 .withPrivateFrameworkBinding("IMSharedUtilities", dependencies: ["IMFoundation"])
 .withPrivateFrameworkBinding("IMFoundation")
 .withPrivateFrameworkBinding("IMDPersistence", dependencies: ["IMSharedUtilities", "IMFoundation"])
 .withPrivateFrameworkBinding("LinkPresentation")
 .withPrivateFrameworkBinding("IDSFoundation")
 .withPrivateFrameworkBinding("IDS", dependencies: ["IDSFoundation"])
 .withPrivateFrameworkBinding("FTServices", dependencies: ["IDSFoundation"])
 .withPrivateFrameworkBinding("CoreSymbolication")
 .withPrivateFrameworkBinding("CommunicationsFilter")
 .withPrivateFrameworkBinding("TextInput")
 .withPrivateFrameworkBinding("RemoteTextInput", dependencies: ["TextInput"])
 .withPrivateFrameworkBinding("TVRemoteCore", dependencies: ["RemoteTextInput"])
 .withPrivateFrameworkBinding("CoreBrightness")
 .withPrivateFrameworkBinding("HID")
 .withPrivateFrameworkBinding("DataDetectorsCore")
 .withPrivateFrameworkBinding("IMDaemonCore", dependencies: ["IMSharedUtilities", "IMFoundation"])
 .withPrivateFrameworkBinding("DigitalTouchShared")
 .withPrivateFrameworkBinding("Security")
 .withParisTarget()
