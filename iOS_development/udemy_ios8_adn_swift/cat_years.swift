//
//  ViewController.swift
//  Cat_Years
//
//  Created by Apple on 12/30/15.
//  Copyright © 2015 hello_world. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    
    //text label (cat years)
    @IBOutlet weak var ageOutput: UILabel!
    
    //text input (human years)
    @IBOutlet weak var ageInput: UITextField!
    
    
    
    
    //action for clicking the button
    @IBAction func calculateTheEdge(sender: AnyObject)
    {

        //acquire human years from the text input
        var human_years_text = Int(ageInput.text!)
        
        //if the user inputed something
        if(human_years_text != nil)
        {
            //multiply by 7
            var cat_years_number = human_years_text! * 7
            //print hte result out in the label
            ageOutput.text = "Your cat is \(String(cat_years_number)) years old in cat years"
        }
        else
        {
            //if the user inputed nothing - spit out an error
            ageOutput.text = "Please enter a number first"
        }
        
    }
    

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}


