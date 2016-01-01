//
//  ViewController.swift
//  how_many_fingers
//
//  Created by Apple on 1/1/16.
//  Copyright © 2016 hello_world. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var label_answer: UILabel!
    @IBOutlet weak var text_input_guess: UITextField!
    @IBAction func button_guess(sender: AnyObject)
    {
        let random_number = arc4random_uniform(6)
        //label_answer.text = String(random_number)
        
        let user_guess = Int(text_input_guess.text!)
        
        if(user_guess != nil && user_guess <= 5)
        {
            if(Int(random_number) == user_guess)
            {
                label_answer.text = "You guessed correctly :)"
            }
            else
            {
                label_answer.text = "You guessed incorrectly :("
            }
        }
        else
        {
            label_answer.text = "You did not enter any number 0-5"
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

