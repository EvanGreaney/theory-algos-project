# theory-algos-project

<h2>SHA512 Algorithm</h2>
The SHA512 algorithm is a one way hashing algorithm that when given a message, processes that message and produces what is called a message or hash digest of a fixed length, for SHA 512 this is of 512 bits in length. "This property is useful in the generation and verification of digital signatures and message authentication codes, and in the generation of random numbers or bits."[3]
<br>
This algorithm is capable of determining the integrity of a message ,as if there is any variation in the message, it is highly likey that the output of that message will result in a seperate hash digest displaying that the message has been tampered with. Below will show how the message is processed and a hash digest is created.
<h3> SHA512 Functions </h3>

![image](https://user-images.githubusercontent.com/37175022/115939739-01ac0600-a497-11eb-9813-72cd59742b24.png)<br>
Fig 1.1 [3]

<h3> SHA512 Constants </h3>

![image](https://user-images.githubusercontent.com/37175022/115939846-5fd8e900-a497-11eb-8de9-cad8161e4f8d.png)<br>
Fig 1.2 [3]
<h3>PreProcessing</h3>
<h4>Input Formatting</h4>
When the input message is taken in, padding is appended to the message to format the message size to be a multiple of 1024 bits (n X 1024). 
It does this by appending bits to the message in order to get the desired length. It uses bits of '0' that are lead by a '1'. Padding is required
and if a message only needs '1' bit of Padding, it will still be appended.

<h3> Padding Size </h3>
After the original message has been appended, the message has to be reperesented in 128 bits, this is because SHA512 can only accept 128bit messages as its input message. Although it has a lmilation on the input size of the message, the number is so large it doesnt cause any issue. The largest number can be represented as (2^128)-1 as the largest input message or if including the single paddit bit it would be (2^128)-2 which would equal: 340,282,366,920,938,463,463,374,607,431,768,211,454 bits in length.[2]


<h4>Hash Buffer Initialization</h4>
The next step is the Hash Buffer initialization, as the algorithm processes each block of 1024 bits from the input message using the result 
from the previous block , it can cause a problem with the very first 1024 bit block as there is no block prior to it that was processed, 
this is rectified by using a  default value for the first block. 

These default values are created by “taking the first 64 bits of the fractional parts of the square roots of the first 8 prime numbers (2,3,5,7,11,13,17,19).
These values are called the Initial Vectors (IV)” [2] which can be seen below . These results then have to be used in the processing of the next block so it needs to be stored for the next block, this is done by the Hash Buffer at the start of processing, it also holds the final hash digest of the entire processing phase of SHA-512 as the last of these results.

![image](https://user-images.githubusercontent.com/37175022/115972464-4a6ec800-a546-11eb-97b3-55c5d6aa6e4b.png)<br>
Fig 1.3 [2]

<h3>Message Processing</h3>
Once the message has been padded and parsed with the inital hash value being set, the next stage is to process the message. It does this by taking each block of 1024 bits and the result of the previous block, one at a time. "The Message block (1024 bit) is expanded out into ‘Words’ using a ‘message sequencer’. Eighty Words to be precise, each of them having a size of 64 bits." [2]<br>
The algorithm then puts the block through a series of what is called "Rounds" or Round Functions as described in Fig 1.4. These rounds require three items before the message can be processed, one "Word", the output of the previous round and a SHA512 constant as seen in Fig 1.2. It uses these items and then processes them and creates a output of 512 bits. This is then repeated for 80 rounds and then the output of the round is then added to the result of the previous block to get the final result for the output to for the message processing
<br>

![image](https://user-images.githubusercontent.com/37175022/115973689-ebfa1780-a54e-11eb-8d02-4e6de3567787.png) 
<br> Fig 1.4 [4]

<h3>Output</h3>
Once the final block has finished with the Message processing phase , the last 512 bit Hash Value belonging to the last 1024 bit block becomes the final hash value of the original message

<h2>Why can't we reverse the SHA512 algorithm to retrieve the original message from a hash digest?</h2>

THe reason why we cant reverse the SHA 512 is because "for each input you have exactly one output, but not the other way around. There are multiple inputs that yields the same output."[5] When taken into consideration for hash values ,there are so many inputs if not an infinite number of inputs that can result in the same output but if we try to reverse the output based on only knowing the output hash value , how can you find the exact inputs used to create that output.
<br>
its like having a maths equation like 50%11 = 6, based on the input given we are given the output of 6 but if you tried to reverse that but only knowing the output of 6, one would have to brute force and try every possible way of reversing the outcome of 6 to get the exact same inputs once more.
<br>
To try a brute force reverse the SHA512 hash digest, one would have to find a collison in the hash algorithm, which would mean we dont need the original message just the  "output of the hash function that is equal to the hash of a valid password".[7] We could then try to find a collision using a "birthday attack" [8] with the formula "O(2^(n/2)) where n is the output length of the hash function in bits"[7] This calucaltes the length of time needed to perform the birtdhay attack. 
<br>
For a SHA 512 digest the time it would take to reverse the algorithm would take O(2^256) time using a birthday attack, which is similar to the rough estimate to the amount of atoms in observalbe universe which is roughly between  10^78 and 10^82 or 2^266[7][9]. The age of the universe is roughly 13.77*10^9 so this would make the time neccessary to brute force the SHA512 Algorithm longer than the current age of the universe.

<h2>Can you design an algorithm that, given enough time, will find input messages that give each of the possible 512-bit strings?</h2>

In theory, relative to how much time it would take it is entirely possible given enough enough to find the input messages of all the possible 512-bit strings but the amount of time it will take to find the input is so high that it is not feasable currently to find all these possible 512-bit strings.

As SHA512 requires a 128 bit input message and with this comes the limitation of of the amount of inputs that can be used by the Algorithm, although a limation exists, the size of the input messages can be of ((2^128)-1) in length or ((2^128)-2) in length if including padding which would be the equivalent of 340,282,366,920,938,463,463,374,607,431,768,211,454 bits.

When then trying to compute the hash output of these maximum inputs of size 2^128 it would require 2^119 successive hash compression operations, if we take that number and and try to convert it to time in seconds it would still take longer than the current age of the universe which is roughly 13.77*10^9 years old.[11]

This would similar to trying to brute force the exact inputs for a given output but in reverse as we would have to test all possible inputs for outputs and if we tried this on a pc that can try 2^40 keys per day it would take 847,904,136,496,835,804,725,427 (848 sextillion) years to compute the operation[11]

In theory it is entirely possbile to find the input messages that give each of the possible 512-bit strings but when we attempt to compute the SHA 512 hash of an ipnut of size 2^128 bits long, it no longer becomes feasible due to not having enough time to compute currently.

<h3>How difficult is it to find a hash digest beginning with at least twelve zeros?</h3>

It can be very difficult when trying to find a hash digest beginning with at least twelve zeroes as when a user is trying to find a hash digest with at least 12 leading zero's, they're most likely using hashes that have been generated randomly. This is mainly seen in bitcoin mining when trying to find what is called a target hash to build a block within a blockchain. Bitcoin Miners take transaction hashes and hash them with a random variable which is a called a nonce which helps the miner get a valid has from the specific block[14][15].

This nonce value is normally started with the value of 1 and then keeps incrementing until the generated hash is the desired target hash for the block to be added to the blockchain, in this case it would be a hash digest with twelve leading zero's. "Block generation is not a long, set problem (like doing a million hashes), but more like a lottery. Each hash basically gives you a random number between 0 and the maximum value of a 256-bit number (which is huge)"[16]. Because of this it can take an extremely long time to find these hash digests. if we were to attempt to find hash values with lower leading zeros like three or four leading zeroes there is a 1 in 2^8 chance of finding a hash digest with three leading zeros[17] or a 1 in 2^12 chance if finding a hash digest with four leading zeros[17]. When we attempt to to find a hash digest with twelve leading zero's there is a 1 in 2^48 chance of finding a hash digest with twhelve leading zeros[17], resulting in a long time needed to find that target hash.

If solely trying to find a block for a blockchain for cryptocurrency like bitcoin a difficulty is applied a block is found faster than ten minutes or slower than ten minutes. For every 2016 blocks mined the code self adjusts depending on how fast the blocks are being mined, if its faster than 10 minutes, the difficulty is increased and the blocks require more leading zeros and if its slower than 10 minutes the difficulty is decreased and blocks with fewer leading zeros are required all to preserve an average of a new block every 10 minutes as to not deplete the total supply of bitcoin which is capped at 21 million bitcoin.

Because of the increase in people trying to mine for cryptocurrenices like bitcoin, the need for finding hashes with 12 leading zeroes and above is increasing, when trying to find these hashes, there is a 1 in 2^48 chance of finding them which will could take several months to find on a standard PC.







<h2>References</h2>
1.	Ahmad, I. and Das, A.S., 2007. Analysis and detection of errors in implementation of SHA-512 algorithms on FPGAs. The computer journal, 50(6), pp.728-738<br>
2.	https://medium.com/@zaid960928/cryptography-explaining-sha-512-ad896365a0c1<br>
3.	Dang, Q. (2015), Secure Hash Standard, Federal Inf. Process. Stds. (NIST FIPS), National Institute of Standards and Technology, Gaithersburg, MD, [online],           https://doi.org/10.6028/NIST.FIPS.180-4 (Accessed April 23, 2021)
4.	http://www.uietkanpur.com/Online_Course/SA_CSE_S510.pdf 
5.	https://stackoverflow.com/questions/47017606/is-hashing-really-a-irreversible-process 
6.	https://crypto.stackexchange.com/questions/45377/why-cant-we-reverse-hashes 
7.	https://stackoverflow.com/questions/6776050/how-long-to-brute-force-a-salted-sha-512-hash-salt-provided
8.	https://en.wikipedia.org/wiki/Birthday_attack 
9.	https://www.universetoday.com/36302/atoms-in-the-universe/#:~:text=At%20this%20level%2C%20it%20is,hundred%20thousand%20quadrillion%20vigintillion%20atoms.
10.	https://crypto.stackexchange.com/questions/45377/why-cant-we-reverse-hashes 
11.	https://crypto.stackexchange.com/questions/64714/why-is-sha-512-limited-to-an-input-of-2128-bits
12.	https://www.nayuki.io/page/lowest-sha512-value-by-brute-force 
13.	https://web.archive.org/web/20171002020748/http://www.h11e.com/ 
14.	https://creativedata.stream/bitcoin-proof-of-work/ 
15.	https://www.javatpoint.com/blockchain-block-hashing 
16.	https://en.bitcoin.it/wiki/Target 
17.	https://crypto.stackexchange.com/questions/89690/sha-512-how-difficult-is-it-to-find-a-hash-digest-beginning-with-at-least-twel
