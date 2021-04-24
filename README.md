# theory-algos-project

<h2>SHA512 Algorithm</h2>
The SHA512 algorithm is a one way hashing algorithm that when given a message, processes that message and produces what is called a message or hash digest of a fixed length, for SHA 512 this is of 512 bits in length. "This property is useful in the generation and verification of digital signatures and message authentication codes, and in the generation of random numbers or bits."[3]
<br>
This algorithm is capable of determining the integrity of a message ,as if there is any variation in the message, it is highly likey that the output of that message will result in a seperate hash digest displaying that the message has been tampered with. Below will show how the message is processed and a hash digest is created.
<h3> SHA512 Functions </h3>

![image](https://user-images.githubusercontent.com/37175022/115939739-01ac0600-a497-11eb-9813-72cd59742b24.png)

<h3> SHA512 Constants </h3>

![image](https://user-images.githubusercontent.com/37175022/115939846-5fd8e900-a497-11eb-8de9-cad8161e4f8d.png)
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
3.	Dang, Q. (2015), Secure Hash Standard, Federal Inf. Process. Stds. (NIST FIPS), National Institute of Standards and Technology, Gaithersburg, MD, [online],           https://doi.org/10.6028/NIST.FIPS.180-4 (Accessed April 23, 2021)
