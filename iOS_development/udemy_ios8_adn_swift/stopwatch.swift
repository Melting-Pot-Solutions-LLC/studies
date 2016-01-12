//
//  ViewController.swift
//  stop_watch
//
//  Created by Apple on 1/12/16.
//  Copyright © 2016 hello_world. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    


    @IBOutlet weak var label_time: UILabel!
    var counter = 0
    var timer = NSTimer()

    
    func count()
    {
        counter++
        print(counter)
        time_label.text = "\(counter)"
    }
    
    func pause()
    {
        timer.invalidate()
    }

    @IBOutlet weak var time_label: UILabel!
    
    @IBAction func start_button(sender: AnyObject) {
        timer = NSTimer.scheduledTimerWithTimeInterval(1, target: self, selector: Selector("count"), userInfo: nil, repeats: true)
    }

    
    @IBAction func stop_button(sender: AnyObject) {
        timer.invalidate()
    }
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        //timer = NSTimer.scheduledTimerWithTimeInterval(1, target: self, selector: Selector("count"), userInfo: nil, repeats: true)
        

    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


    

    

}


