# theory-algos-project

<h2>SHA512 Algorithm</h2>
<h3>Input Formatting</h3>
When the input message is taken in, padding is appended to the message to format the message size to be a multiple of 1024 bits (n X 1024). 
It does this by appending bits to the message in order to get the desired length. It uses bits of '0' that are lead by a '1'. Padding is required
and if a message only needs '1' bit of Padding, it will still be appended.

<h3>Hash Buffer Initialization</h3>
The next step is the Hash Buffer initialization, as the algorithm processes each block of 1024 bits from the input message using the result 
from the previous block , it can cause a problem with the very first 1024 bit block as there is no block prior to it that was processed, 
this is rectified by using a  default value for the first block. 

These default values are created by “taking the first 64 bits of the fractional parts of the square roots of the first 8 prime numbers (2,3,5,7,11,13,17,19).
These values are called the Initial Vectors (IV)” [2]. These results then have to be used in the processing of the next block so it needs to be stored for the next block, 
this is done by the Hash Buffer at the start of processing, it also holds the final hash digest of the entire processing phase of SHA-512 as the last of these results.


<h2>References</h2>
1.	Ahmad, I. and Das, A.S., 2007. Analysis and detection of errors in implementation of SHA-512 algorithms on FPGAs. The computer journal, 50(6), pp.728-738
2.	https://medium.com/@zaid960928/cryptography-explaining-sha-512-ad896365a0c1
