
#include <iostream>
using namespace std;

void sendEmail(string addr, string subject, string content, string attachment=""){
    // Sending a command looks like:
    // echo "content" | mailx -s "subject" -a "attachment" addr;
    // TODO: Search how you can run a unix command in C++
    // TODO: You need to add double quotation character (") to both sides of strings for this command. Adding other characters (like ? in code below) should be easy, but double quotation says: I'm a character but not a typical character! 
    // string new_str = '?' + old_str + '?'
    // TODO: Complete this method

    addr = "\"" + addr + "\"";
    content = "\"" + content + "\"";
    subject = "\"" + subject + "\"";
    string cmd;
    cmd = "echo " + content + " | mailx -s " + subject + " ";
    if (attachment == "")
        cmd += addr;
    else {
        attachment = "\"" + attachment + "\"";
        cmd += "-a "  + attachment + " " + addr;
    }
    cout << "|" << cmd << "|" << endl;
    system(cmd.c_str());
}




int main(){

    string addr = "abri442@usc.edu";
    string subject = "This is from our server Sahand";
    string content = "Hi, this is Saeed, I made this sample email to test my code";


    sendEmail(addr, subject, content);

    return 0;
}

