/*
Ara Reighard
12/25/2025


Collaborators: None
Sources:
 - https://www.geeksforgeeks.org/c/read-a-file-line-by-line-in-c/
 - https://www.geeksforgeeks.org/c/how-to-split-a-string-by-a-delimiter-in-c/
 - https://www.geeksforgeeks.org/c/convert-string-to-int-in-c/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct email {
    // has the structure for all the objects that would be in an email
    char* sender;
    char* subject;
    int senderId;
    int year;
    int month;
    int day;
} email;

email emails[1024];
int emailsLength = 0;

// checks if an email is greater than another email
int _emailGreaterThan(int index1, int index2) {
    email email1 = emails[index1];
    email email2 = emails[index2];
    // if the sender ids are not the same return which email is greater
    if (email1.senderId == email2.senderId) {
        if (email1.year <= email2.year && email1.month <= email2.month && email1.day <= email2.day) return 1;
        else return 0; 
    }

    else return email1.senderId > email2.senderId;
}

// checks if an email is less than another email
int _emailLessThan(int index1, int index2) {
    // bad, but we won't encounter two emails of equal values so it's fine
    return !_emailGreaterThan(index1, index2);
}

// swaps two emails
void _swapEmails(int index1, int index2) {
    email tempEmail = emails[index1];
    emails[index1] = emails[index2];
    emails[index2] = tempEmail;
}

// makes sure a newly added node is in the correct location in the heap
void _upheap(int index) {
    int parentIndex = (index - 1) / 2;
    
    // if the index is not the bottom of the heap
    if (index != 0) {
        // if the email is greater than parent email, swap them and recurse further at the parent index
        if (_emailGreaterThan(index, parentIndex)) {
            _swapEmails(index, parentIndex);
            _upheap(parentIndex);
        }
    }
}

// organizes the heap from the bottom up
void _downheap(int index) {
    int leftIndex = index * 2 + 1;
    int rightIndex = index + 2 + 2;
    int parentIndex = (index - 1) / 2;
    // if children exist, try to swap with the greater child
    if (rightIndex < emailsLength) {
        // if the right child is greater than left and itself, swap
        if (_emailGreaterThan(leftIndex, rightIndex) && _emailLessThan(index, rightIndex)) {
            _swapEmails(index, rightIndex);
            // continue downheaping from the right child index
            _downheap(rightIndex);
        }
        // if the left child is greater than right and itself, swap
        else if (_emailLessThan(leftIndex, rightIndex) && _emailLessThan(index, leftIndex)) {
            _swapEmails(index, leftIndex);
            // continue downheaping from the left child index
            _downheap(leftIndex);
        }
    }

    // if a left child exists, try to swap
    else if (leftIndex < emailsLength) {
        // if the left child is greater than itself, swap
        if (_emailLessThan(index, leftIndex)) {
            _swapEmails(index, leftIndex);
        }
    }

}

// removes the maximum value email and returns it
email pop() {
    // does this by swapping the max email with the smallest email and downheaping from there
    _swapEmails(0, emailsLength - 1);
    email oldEmail = emails[emailsLength - 1];
    _downheap(0);
    return oldEmail;
}

void addEmail(email emailToAdd) {
    emails[++emailsLength] = emailToAdd;
    _upheap(emailsLength - 1);
}

int main() {
    FILE* file;
    file = fopen("Assignment5_Test_File.txt", "r");

    // makes sure the file was actually opened
    if (file != NULL) {
        char line[2048];

        while (fgets(line, sizeof(line), file)) {
            printf("%s\n", line);

            if (strstr(line, "EMAIL") == line) {
                
                char* component = strtok(line, ",");
                email newEmail;

                printf("STRING: %s", component);
                
                newEmail.sender = component;
                char person[256] = "";
                char uselessString[256] = "";
                component = sscanf(component, "%5s %250[^\n]", uselessString, person);

                if (newEmail.sender == "Boss") newEmail.senderId = 5;
                else if (newEmail.sender == "Subordinate") newEmail.senderId = 4;
                else if (newEmail.sender == "Peer") newEmail.senderId = 3;
                else if (newEmail.sender == "ImportantPerson") newEmail.senderId = 2;
                else newEmail.senderId = 1;

                component = strtok(NULL, ",");
                printf("STRING: %s", component);

                newEmail.subject = component;
                
                component = strtok(NULL, ",");
                printf("STRING: %s", component);

                char* date = strtok(component, "-");

                newEmail.month = atoi(date);
                date = strtok(NULL, "-");
                newEmail.day = atoi(date);
                date = strtok(NULL, "-");
                date[strcspn(date, "\n")] = '\0';
                printf("YEAR: %s", date);
                newEmail.year = atoi(date);

                addEmail(newEmail);
            }

            // Shows the top email
            if (strstr(line, "NEXT") == line) {
                // if the length isn't more than 0 say there are no emails
                if (emailsLength <= 0) printf("No emails in inbox.\n");
                // otherwise pop the top email
                else {
                    email nextEmail = emails[0];
                    printf("\nSender: %s \nSubject: %s \nDate: %d-%d-%d\n", nextEmail.sender, nextEmail.subject, nextEmail.month, nextEmail.day, nextEmail.year);
                }
            }

            // Reads the top email
            if (strstr(line, "READ") == line) {
                // if the length isn't more than 0 say there are no emails
                if (emailsLength <= 0) printf("No emails in inbox.\n");
                // otherwise pop the top email
                else pop();
            }

            if (strstr(line, "COUNT") == line) {
                printf("There are %d emails waiting in queue.", emailsLength);
            }



            

        }

        fclose(file);
    }

    return 0;

}    