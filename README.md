SMTP Client for Qt (C++)
========================

The SmtpClient for Qt is small library writen for Qt 4 (C++ version) that allows application to send complex emails (plain text, html, attachments, inline files, etc.) using the Simple Mail Transfer Protocol (SMTP).


## SMPT Client for Qt supports

- TCP and SSL connections to SMTP servers

- SMTP authentification (PLAIN and LOGIN methods)

- sending MIME emails (to multiple recipients)

- plain text and HTML (with inline files) content in emails

- multiple attachments and inline files (used in HTML)

- diferent character sets (ascii, utf-8, etc) and encoding methods (7bit, 8bit, base64)

- error handling

## Examples

Lets see a simple example:


    #include <QtGui/QApplication>
    #include "../src/SmtpMime"

    int main(int argc, char *argv[])
    {
        QApplication a(argc, argv);

        // This is a first demo application of the SmtpClient for Qt project

        // First we need to create an SmtpClient object
        // We will use the Gmail's smtp server (smtp.gmail.com, port 465, ssl)

        SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

        // We need to set the username (your email address) and the password
        // for smtp authentification.

        smtp.setUser("your_email_address@gmail.com");
        smtp.setPassword("your_password");

        // Now we create a MimeMessage object. This will be the email.

        MimeMessage message;

        message.setSender(new EmailAddress("your_email_address@gmail.com", "Your Name"));
        message.addRecipient(new EmailAddress("recipient@host.com", "Recipient's Name"));
        message.setSubject("SmtpClient for Qt - Demo");

        // Now add some text to the email.
        // First we create a MimeText object.

        MimeText text;

        text.setText("Hi,\nThis is a simple email message.\n");

        // Now add it to the mail

        message.addPart(&text);

        // Now we can send the mail

        smtp.connectToHost();
        smtp.login();
        smtp.sendMail(message);
        smtp.quit();

    }


## License

This project (all files including the demos/examples) is licensed under the GNU GPL version 2.0.

**Copyright (c) 2011 - Tőkés Attila**