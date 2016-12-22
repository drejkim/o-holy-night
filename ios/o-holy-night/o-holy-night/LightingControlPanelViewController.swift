//
//  LightingControlPanelViewController.swift
//  o-holy-night
//
//  Created by Esther Jun Kim on 12/21/16.
//  Copyright © 2016 Esther Jun Kim. All rights reserved.
//

import UIKit
import ParticleSDK

// REPLACE WITH YOUR PARTICLE INFORMATION
let particleUsername = "USERNAME"
let particlePassword = "PASSWORD"
let particleDeviceName = "DEVICE NAME"

var myPhoton:SparkDevice?

class LightingControlPanelViewController: UITableViewController {
    
    @IBOutlet weak var switchManger: UISwitch!
    @IBOutlet weak var switchSky: UISwitch!
    @IBOutlet weak var switchStar: UISwitch!

    @IBOutlet weak var pulseBtnManger: UIButton!
    @IBOutlet weak var pulseBtnSky: UIButton!
    @IBOutlet weak var pulseBtnStar: UIButton!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Disable cell selection highlighting
        tableView.allowsSelection = false
        
        SparkCloud.sharedInstance().login(withUser: particleUsername, password: particlePassword) { (error:Error?) in
            if let e = error {
                print(e)
            }
            else {
                print("Logged in!")
            }
        }
        
        SparkCloud.sharedInstance().getDevices { (sparkDevices:[SparkDevice]?, error:Error?) in
            if let e = error {
                print(e)
            }
            else {
                if let devices = sparkDevices as [SparkDevice]! {
                    for device in devices {
                        if device.name == particleDeviceName {
                            myPhoton = device
                            
                            print(myPhoton!.id)
                        }
                    }
                }
            }
        }
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func toggleMangerSwitch() {
        let funcArgs=[getSwitchStateAsString(isOn:switchManger.isOn)]
        callParticleFunction(name: "manger", args: funcArgs)
    }
    
    @IBAction func toggleSkySwitch() {
        let funcArgs=[getSwitchStateAsString(isOn:switchSky.isOn)]
        callParticleFunction(name: "sky", args: funcArgs)
    }
    
    @IBAction func toggleStarSwitch() {
        let funcArgs=[getSwitchStateAsString(isOn:switchStar.isOn)]
        callParticleFunction(name: "star", args: funcArgs)
    }
    
    @IBAction func pulseManger() {
        if(pulseBtnManger.isTouchInside) {
            let funcArgs=["pulse"]
            callParticleFunction(name: "manger", args: funcArgs)
        }
    }
    
    @IBAction func pulseSky() {
        if(pulseBtnSky.isTouchInside) {
            let funcArgs=["pulse"]
            callParticleFunction(name: "sky", args: funcArgs)
        }
    }
    
    @IBAction func pulseStar() {
        if(pulseBtnStar.isTouchInside) {
            let funcArgs=["pulse"]
            callParticleFunction(name: "star", args: funcArgs)
        }
    }
    
    func getSwitchStateAsString(isOn:Bool) -> String {
        if(isOn) {
            return "on"
        }
        else {
            return "off"
        }
    }
    
    func callParticleFunction(name:String, args:[Any]?) {
        myPhoton!.callFunction(name, withArguments: args) { (resultCode:NSNumber?, error:Error?) in
            if let e = error {
                print(e)
            }
            else {
                print(resultCode!)
            }
        }
    }
    
}

