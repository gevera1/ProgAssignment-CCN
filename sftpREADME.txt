Name: Adrian-James Gevero

inputfile.txt: 	First Chapter of Lewis Carroll's ALICE IN WONDERLAND

Server IP:	Localhost (127.0.0.1) Port 9093
Client IP:	Localhost (127.0.0.1) Ephemeral Port


struct pkt {
	char seqnum, acknum, finnum, data[ BUFF_SIZE ];
};

       -> I am aware that the assignment PDF said that a fin is not necessary, however,
	  due to the structure of the packet data type, a FIN field was deemed necessary.
	  This is to prevent any major memory leaks or invalid read/write's on either 
	  end. Because the data member variable is a fixed 512 bytes, there is no way to
	  send or receive a packet with a data variable smaller than 512 bytes. 

	  I have tried numerous ways to counteract this issue, but all paths led to 
	  overengineering and generally bad code.

	  In general, the way the code is designed, the packets sent over only ever have
	  an addition ONE (1) bit attached. This is because the client only sets a SEQ
	  number and the Server only returns a packet with a single ACK value. For the 
	  final packet, only a FIN variable is set along with some arbitrary data.


	  There are momentary deadlocks in the program, however, they require a sufficiently
	  large file and a high enough loss rate for this to occur. This has been rectified 
	  with a server timeout clock lasting 10 seconds.




UNIX diff OUTPUT: "" [NO DIFFERENCE BETWEEN INPUT AND OUTPUT!]


HOW MY PROGRAM HANDLES OUT OF ORDER ACKs: Retransmission! 
	- If the server timesout, it sends an out of order ACK, which causes a retransmission
		on the client side

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

TEST: LOSS RATE = 0 ; AVERAGE DELAY = 100us
-------------------------------------------

	The test used to determine the functionality of the code was to send over the
	first chapter of ALICE IN WONDERLAND. This is a good stress test because it is
	not just a continuous stream of characters, there are blank lines and 
	formatting characters that need to be accounted for. 

	Initially, just the correctness of the code needed to be checked. In later tests
	we will see how LOSS_RATE and AVERAGE_DELAY come into play.

SERVER OUTPUT:
==============

Waiting for packet...
Packet received.
	String length: 64
	String: The Project Gutenberg Etext of Alice's Adventures in Wonderland

Waiting for packet...
Packet received.
	String length: 61
	String: This is an HTML reprint of #1 in our series by Lewis Carroll

Waiting for packet...
Packet received.
	String length: 1
	String: 

Waiting for packet...
Packet received.
	String length: 1
	String: 

Waiting for packet...
Packet received.
	String length: 1
	String: 

Waiting for packet...
Packet received.
	String length: 1
	String: 

Waiting for packet...
Packet received.
	String length: 33
	String: ALICE'S ADVENTURES IN WONDERLAND

Waiting for packet...
Packet received.
	String length: 14
	String: Lewis Carroll

Waiting for packet...
Packet received.
	String length: 35
	String: THE MILLENNIUM FULCRUM EDITION 3.0

Waiting for packet...
Packet received.
	String length: 1
	String: 

Waiting for packet...
Packet received.
	String length: 10
	String: CHAPTER I

Waiting for packet...
Packet received.
	String length: 21
	String: Down the Rabbit-Hole

Waiting for packet...
Packet received.
	String length: 302
	String: Alice was beginning to get very tired of sitting by her sister on the bank, and of having nothing to do: once or twice she had peeped into the book her sister was reading, but it had no pictures or conversations in it, 'and what is the use of a book,' thought Alice 'without pictures or conversation?'

Waiting for packet...
Packet received.
	String length: 1
	String: 

Waiting for packet...
Packet received.
	String length: 290
	String: So she was considering in her own mind (as well as she could, for the hot day made her feel very sleepy and stupid), whether the pleasure of making a daisy-chain would be worth the trouble of getting up and picking the daisies, when suddenly a White Rabbit with pink eyes ran close by her.

Waiting for packet...
Packet received.
	String length: 1
	String: 

Waiting for packet...
Packet received.
	String length: 511
	String: There was nothing so very remarkable in that; nor did Alice think it so very much out of the way to hear the Rabbit say to itself, 'Oh dear! Oh dear! I shall be late!' (when she thought it over afterwards, it occurred to her that she ought to have wondered at this, but at the time it all seemed quite natural); but when the Rabbit actually took a watch out of its waistcoat-pocket, and looked at it, and then hurried on, Alice started to her feet, for it flashed across her mind that she had never before seen 
Waiting for packet...
Packet received.
	String length: 223
	String: a rabbit with either a waistcoat-pocket, or a watch to take out of it, and burning with curiosity, she ran across the field after it, and fortunately was just in time to see it pop down a large rabbit-hole under the hedge.

Waiting for packet...
Packet received.
	String length: 1
	String: 

Waiting for packet...
Packet received.
	String length: 110
	String: In another moment down went Alice after it, never once considering how in the world she was to get out again.

Waiting for packet...
Packet received.
	String length: 1
	String: 

Waiting for packet...
Packet received.
	String length: 220
	String: The rabbit-hole went straight on like a tunnel for some way, and then dipped suddenly down, so suddenly that Alice had not a moment to think about stopping herself before she found herself falling down a very deep well.

Waiting for packet...
Packet received.
	String length: 1
	String: 

Waiting for packet...
Packet received.
	String length: 511
	String: Either the well was very deep, or she fell very slowly, for she had plenty of time as she went down to look about her and to wonder what was going to happen next. First, she tried to look down and make out what she was coming to, but it was too dark to see anything; then she looked at the sides of the well, and noticed that they were filled with cupboards and book-shelves; here and there she saw maps and pictures hung upon pegs. She took down a jar from one of the shelves as she passed; it was labelled 'OR
Waiting for packet...
Packet received.
	String length: 194
	String: ANGE MARMALADE', but to her great disappointment it was empty: she did not like to drop the jar for fear of killing somebody, so managed to put it into one of the cupboards as she fell past it.

Waiting for packet...
Packet received.
	String length: 1
	String: 

Waiting for packet...
Packet received.
	String length: 260
	String: 'Well!' thought Alice to herself, 'after such a fall as this, I shall think nothing of tumbling down stairs! How brave they'll all think me at home! Why, I wouldn't say anything about it, even if I fell off the top of the house!' (Which was very likely true.)

Waiting for packet...
Packet received.
	String length: 1
	String: 

Waiting for packet...
Packet received.
	String length: 511
	String: Down, down, down. Would the fall never come to an end! 'I wonder how many miles I've fallen by this time?' she said aloud. 'I must be getting somewhere near the centre of the earth. Let me see: that would be four thousand miles down, I think--' (for, you see, Alice had learnt several things of this sort in her lessons in the schoolroom, and though this was not a very good opportunity for showing off her knowledge, as there was no one to listen to her, still it was good practice to say it over) '--yes, that
Waiting for packet...
Packet received.
	String length: 195
	String: 's about the right distance--but then I wonder what Latitude or Longitude I've got to?' (Alice had no idea what Latitude was, or Longitude either, but thought they were nice grand words to say.)

Waiting for packet...
Packet received.
	String length: 1
	String: 

Waiting for packet...
Packet received.
	String length: 511
	String: Presently she began again. 'I wonder if I shall fall right through the earth! How funny it'll seem to come out among the people that walk with their heads downward! The Antipathies, I think--' (she was rather glad there was no one listening, this time, as it didn't sound at all the right word) '--but I shall have to ask them what the name of the country is, you know. Please, Ma'am, is this New Zealand or Australia?' (and she tried to curtsey as she spoke--fancy curtseying as you're falling through the air!
Waiting for packet...
Packet received.
	String length: 171
	String:  Do you think you could manage it?) 'And what an ignorant little girl she'll think me for asking! No, it'll never do to ask: perhaps I shall see it written up somewhere.'

Waiting for packet...
Packet received.
	String length: 1
	String: 

Waiting for packet...
Packet received.
	String length: 511
	String: Down, down, down. There was nothing else to do, so Alice soon began talking again. 'Dinah'll miss me very much to-night, I should think!' (Dinah was the cat.) 'I hope they'll remember her saucer of milk at tea-time. Dinah my dear! I wish you were down here with me! There are no mice in the air, I'm afraid, but you might catch a bat, and that's very like a mouse, you know. But do cats eat bats, I wonder?' And here Alice began to get rather sleepy, and went on saying to herself, in a dreamy sort of way, 'Do 
Waiting for packet...
Packet received.
	String length: 470
	String: cats eat bats? Do cats eat bats?' and sometimes, 'Do bats eat cats?' for, you see, as she couldn't answer either question, it didn't much matter which way she put it. She felt that she was dozing off, and had just begun to dream that she was walking hand in hand with Dinah, and saying to her very earnestly, 'Now, Dinah, tell me the truth: did you ever eat a bat?' when suddenly, thump! thump! down she came upon a heap of sticks and dry leaves, and the fall was over.

Waiting for packet...
Packet received.
	String length: 1
	String: 

Waiting for packet...
Packet received.
	String length: 511
	String: Alice was not a bit hurt, and she jumped up on to her feet in a moment: she looked up, but it was all dark overhead; before her was another long passage, and the White Rabbit was still in sight, hurrying down it. There was not a moment to be lost: away went Alice like the wind, and was just in time to hear it say, as it turned a corner, 'Oh my ears and whiskers, how late it's getting!' She was close behind it when she turned the corner, but the Rabbit was no longer to be seen: she found herself in a long, 
Waiting for packet...
Packet received.
	String length: 68
	String: low hall, which was lit up by a row of lamps hanging from the roof.

Waiting for packet...
Packet received.
	String length: 1
	String: 

Waiting for packet...
Packet received.
	String length: 229
	String: There were doors all round the hall, but they were all locked; and when Alice had been all the way down one side and up the other, trying every door, she walked sadly down the middle, wondering how she was ever to get out again.

Waiting for packet...
Packet received.
	String length: 1
	String: 

Waiting for packet...
Packet received.
	String length: 511
	String: Suddenly she came upon a little three-legged table, all made of solid glass; there was nothing on it except a tiny golden key, and Alice's first thought was that it might belong to one of the doors of the hall; but, alas! either the locks were too large, or the key was too small, but at any rate it would not open any of them. However, on the second time round, she came upon a low curtain she had not noticed before, and behind it was a little door about fifteen inches high: she tried the little golden key i
Waiting for packet...
Packet received.
	String length: 48
	String: n the lock, and to her great delight it fitted!

Waiting for packet...
Packet received.
	String length: 1
	String: 

Waiting for packet...
Packet received.
	String length: 511
	String: Alice opened the door and found that it led into a small passage, not much larger than a rat-hole: she knelt down and looked along the passage into the loveliest garden you ever saw. How she longed to get out of that dark hall, and wander about among those beds of bright flowers and those cool fountains, but she could not even get her head though the doorway; 'and even if my head would go through,' thought poor Alice, 'it would be of very little use without my shoulders. Oh, how I wish I could shut up like
Waiting for packet...
Packet received.
	String length: 208
	String:  a telescope! I think I could, if I only know how to begin.' For, you see, so many out-of-the-way things had happened lately, that Alice had begun to think that very few things indeed were really impossible.

Waiting for packet...
Packet received.
	String length: 1
	String: 

Waiting for packet...
Packet received.
	String length: 423
	String: There seemed to be no use in waiting by the little door, so she went back to the table, half hoping she might find another key on it, or at any rate a book of rules for shutting people up like telescopes: this time she found a little bottle on it, ('which certainly was not here before,' said Alice,) and round the neck of the bottle was a paper label, with the words 'DRINK ME' beautifully printed on it in large letters.

Waiting for packet...
Packet received.
	String length: 1
	String: 

Waiting for packet...
Packet received.
	String length: 511
	String: It was all very well to say 'Drink me,' but the wise little Alice was not going to do that in a hurry. 'No, I'll look first,' she said, 'and see whether it's marked "poison" or not'; for she had read several nice little histories about children who had got burnt, and eaten up by wild beasts and other unpleasant things, all because they would not remember the simple rules their friends had taught them: such as, that a red-hot poker will burn you if you hold it too long; and that if you cut your finger very 
Waiting for packet...
Packet received.
	String length: 183
	String: deeply with a knife, it usually bleeds; and she had never forgotten that, if you drink much from a bottle marked 'poison,' it is almost certain to disagree with you, sooner or later.

Waiting for packet...
Packet received.
	String length: 1
	String: 

Waiting for packet...
Packet received.
	String length: 260
	String: However, this bottle was not marked 'poison,' so Alice ventured to taste it, and finding it very nice, (it had, in fact, a sort of mixed flavour of cherry-tart, custard, pine-apple, roast turkey, toffee, and hot buttered toast,) she very soon finished it off.

Waiting for packet...
Packet received.
	String length: 1
	String: 

Waiting for packet...
Packet received.
	String length: 1
	String: 

Waiting for packet...
Packet received.
	String length: 1
	String: 

Waiting for packet...
Packet received.
	String length: 80
	String: 'What a curious feeling!' said Alice; 'I must be shutting up like a telescope.'

Waiting for packet...
Packet received.
	String length: 1
	String: 

Waiting for packet...
Packet received.
	String length: 511
	String: And so it was indeed: she was now only ten inches high, and her face brightened up at the thought that she was now the right size for going through the little door into that lovely garden. First, however, she waited for a few minutes to see if she was going to shrink any further: she felt a little nervous about this; 'for it might end, you know,' said Alice to herself, 'in my going out altogether, like a candle. I wonder what I should be like then?' And she tried to fancy what the flame of a candle is like
Waiting for packet...
Packet received.
	String length: 90
	String:  after the candle is blown out, for she could not remember ever having seen such a thing.

Waiting for packet...
Packet received.
	String length: 1
	String: 

Waiting for packet...
Packet received.
	String length: 511
	String: After a while, finding that nothing more happened, she decided on going into the garden at once; but, alas for poor Alice! when she got to the door, she found she had forgotten the little golden key, and when she went back to the table for it, she found she could not possibly reach it: she could see it quite plainly through the glass, and she tried her best to climb up one of the legs of the table, but it was too slippery; and when she had tired herself out with trying, the poor little thing sat down and c
Waiting for packet...
Packet received.
	String length: 6
	String: ried.

Waiting for packet...
Packet received.
	String length: 1
	String: 

Waiting for packet...
Packet received.
	String length: 511
	String: 'Come, there's no use in crying like that!' said Alice to herself, rather sharply; 'I advise you to leave off this minute!' She generally gave herself very good advice, (though she very seldom followed it), and sometimes she scolded herself so severely as to bring tears into her eyes; and once she remembered trying to box her own ears for having cheated herself in a game of croquet she was playing against herself, for this curious child was very fond of pretending to be two people. 'But it's no use now,' t
Waiting for packet...
Packet received.
	String length: 120
	String: hought poor Alice, 'to pretend to be two people! Why, there's hardly enough of me left to make one respectable person!'

Waiting for packet...
Packet received.
	String length: 1
	String: 

Waiting for packet...
Packet received.
	String length: 408
	String: Soon her eye fell on a little glass box that was lying under the table: she opened it, and found in it a very small cake, on which the words 'EAT ME' were beautifully marked in currants. 'Well, I'll eat it,' said Alice, 'and if it makes me grow larger, I can reach the key; and if it makes me grow smaller, I can creep under the door; so either way I'll get into the garden, and I don't care which happens!'

Waiting for packet...
Packet received.
	String length: 1
	String: 

Waiting for packet...
Packet received.
	String length: 447
	String: She ate a little bit, and said anxiously to herself, 'Which way? Which way?', holding her hand on the top of her head to feel which way it was growing, and she was quite surprised to find that she remained the same size: to be sure, this generally happens when one eats cake, but Alice had got so much into the way of expecting nothing but out-of-the-way things to happen, that it seemed quite dull and stupid for life to go on in the common way.

Waiting for packet...
Packet received.
	String length: 1
	String: 

Waiting for packet...
Packet received.
	String length: 57
	String: So she set to work, and very soon finished off the cake.

Waiting for packet...
Packet received.
	String length: 1
	String: 

Waiting for packet...
Packet received.
	String length: 1
	String: 

Waiting for packet...
Packet received.
	String length: 1
	String: 

Waiting for packet...
Packet received.
	String length: 14
	String: request close


All packets received successfully. Killing Server

[CORRESPONDING]
CLIENT OUTPUT:
==============

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Packet...
Size: 512
Waiting for ACK...
Received ACK

Sending Last Packet...
Size: 512
Received ACK

sFTP: file sent successfully to 127.0.0.1 in 0.00735 secs

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

TEST: LOSS_RATE = 100 ; AVERAGE_DELAY = 0 us
--------------------------------------------

SERVER OUTPUT:
--------------

Waiting for packet...
Packet received.
	String length: 64
	String: The Project Gutenberg Etext of Alice's Adventures in Wonderland

Simulating Lost ACK
Waiting for packet...
Packet received.
	String length: 64
	String: The Project Gutenberg Etext of Alice's Adventures in Wonderland

Simulating Lost ACK
Waiting for packet...
Packet received.
	String length: 64
	String: The Project Gutenberg Etext of Alice's Adventures in Wonderland

Simulating Lost ACK
Waiting for packet...
Packet received.
	String length: 64
	String: The Project Gutenberg Etext of Alice's Adventures in Wonderland

Simulating Lost ACK
Waiting for packet...
Packet received.
	String length: 64
	String: The Project Gutenberg Etext of Alice's Adventures in Wonderland

Simulating Lost ACK
Waiting for packet...

Server Terminated.


CLIENT OUTPUT:
==============

Sending Packet...
Size: 512
Waiting for ACK...

Retransmitting...
Sending Packet...
Size: 512
Waiting for ACK...

Retransmitting...
Sending Packet...
Size: 512
Waiting for ACK...

Retransmitting...
Sending Packet...
Size: 512
Waiting for ACK...

Retransmitting...
Sending Packet...
Size: 512
Waiting for ACK...

Retransmitting...
sFTP: file transfer unsuccessful: packet retransmission limit reached
