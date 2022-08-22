//
//  File.swift
//  
//
//  Created by Eric Rabil on 8/20/22.
//

import Foundation

import AddressBookCore
import AOSAccounts
import AOSKit
import AOSUI
import AppleAccount
import AuthKit
import AuthKitUI
import CommunicationsFilter
import CoreBrightness
import CoreSymbolication
import DarwinPrivate
import DataDetectorsCore
import DigitalTouchShared
import FTServices
import HID
import HTTPServer
import IDS
import IDSFoundation
import IMCore
import IMDaemonCore
import IMDPersistence
import IMFoundation
import IMSharedUtilities
import LinkPresentation
import LoggingSupport
import login
import RemoteTextInput
import Security
import SkyLight
import SystemAdministration
import TextInput
import TVRemoteCore

@_cdecl("main") func main() {
    _ = LPVideo()
    _ = LPImage()
    _ = IMItem()
    _ = IMMessageItem()
    _ = IMMessage()
    _ = IMChatStyle.group
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
