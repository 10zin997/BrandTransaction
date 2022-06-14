# DATA Strucutre Project 
## Reading from an input file.

"ABC" Hardware Co has hired you to write a program for its Accounts Receivable dept.

Two types of input data:

    1. A master file in ascending order by customer number (customer numbers are 4 digits).
    The file also contains a 20 character customer name and balance due.

    2. A transaction file that contains records of each transaction. This file is also in
    ascending order by customer number. There should be more than one transaction record per master
    record. Each related group of data in a file is called a record. A record should be
    stored in a structure.

Each record starts with a character, "O" for order or "P" for payment. Each record
also contains the four-digit customer number, a four-digit transaction number, and up to
three more values:

    If the code is "O", the record contains the item ordered (20 characters), the
    quantity ordered (an int) plus the cost of the item. (multiply to get total cost)

    if the code is "P", the record contains the amount of payment.

You are to read in records one at a time from the two files. Process all transaction
records for each master record
before going on to the next master record. If the transaction record contains an "O"
in col 1, calculate the order amount and add it to the balance due. If the record
contains a "P" in col 1, subtract the payment from the balance due. Keep a running total
of the A/R Balance of ABC Company (sum of balances due for each customer).

Your program should...

Check for errors such as duplicate master records or records in the transaction file
that do not appear in the master file.

After processing a master record and all its transactions the program should prepare
an invoice for each customer which lists the customer name, number, previous balance
(balance before transactions were performed), all transactions, and the final balance
due (balance after transactions are performed).

Output should look something like...

# CUSTOMER NAME   CUSTOMER NUMBER

                          
|               |               | PREVIOUS BALANCE  $XXX.XX  |
| ------------- |:-------------:| --------------:|
| TRANSACTION # | ITEM ORDERED  | $ ORDER AMOUNT |
| TRANSACTION # | ITEM ORDERED  | $ ORDER AMOUNT |
| TRANSACTION # | ITEM ORDERED  | $ ORDER AMOUNT |
|  TRANSACTION #| ITEM ORDERED  | $ ORDER AMOUNT |
|               |               | BALANCE DUE $XXX.XX          |

Don't forget, payments reduce the balance and orders increase it. You are to create
your own data using at least 7 customers with an average of 5 transactions each.
