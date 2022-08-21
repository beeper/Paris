//
//  File.swift
//  
//
//  Created by Eric Rabil on 8/20/22.
//

import Foundation
import IMCore
import LinkPresentation
import IMDPersistence
import IMSharedUtilities
import IMFoundation
import IDS
import IDSFoundation
import FTServices
import CommunicationsFilter
import CoreSymbolication
import TextInput
import RemoteTextInput
import TVRemoteCore
import CoreBrightness
import HID
import DataDetectorsCore

@_cdecl("main") func main() {
    _ = LPVideo()
    _ = LPImage()
    _ = IMItem()
    _ = IMMessageItem()
    _ = IMMessage()
    _ = IMChatStyle.groupChatStyle
    _ = ("" as NSString)._bestGuessURI()
    _ = IMDIsRunningInDatabaseServerProcess()
    _ = IDSService()
    _ = IDSBaseMessage()
    _ = FTMessageDelivery_DualMode()
    _ = CreateCMFItemFromString("")
    _ = CSSymbolicatorCreateWithTask(mach_task_self_)
    _ = TIDocumentState()
    _ = RTIDocumentState()
    _ = TVRCButton()
    _ = BrightnessSystemClient()
    _ = HIDServiceClient()
    print("called everything")
}
