Name: Adrian-James Gevero

Message [56 Bytes]: 	"The horse is the white of the eyes and the dark within.\n"
Server IP:		Localhost (127.0.0.1)
Client IP:		Localhost (127.0.0.1)

+-------------------------------------------------------------------------------------+
|PING Tests: Increase amount of loops, No packet loss, All packet loss, 100 msec delay|
+-------------------------------------------------------------------------------------+

The tests chosen were to ensure functionality of both the server and the client. The message
 was kept simple and not changed in order to focus on the architecture and efficiency of the
 software written. Writing both the client and server in C, the unp.h header file was used
 in order to facilitate a relatively smooth implementation of socket programming in C.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Test: 5 Loops, 30% Packet Loss

CLIENT OUTPUT:
--------------
PING 127.0.0.1   0 LOST
PING 127.0.0.1   1 0.000037
PING 127.0.0.1   2 0.000066
PING 127.0.0.1   3 0.000085
PING 127.0.0.1   4 0.000093

COMPLETED:      4 packets received,     1 packets lost

SERVER OUTPUT:
--------------
Received from 127.0.0.1: The horse is the white of the eyes and the dark within.
    Reply not sent.

Received from 127.0.0.1: The horse is the white of the eyes and the dark within.
    Reply not sent.

Received from 127.0.0.1: The horse is the white of the eyes and the dark within.
    Reply sent.

Received from 127.0.0.1: The horse is the white of the eyes and the dark within.
    Reply sent.

Received from 127.0.0.1: The horse is the white of the eyes and the dark within.
    Reply sent.

Received from 127.0.0.1: The horse is the white of the eyes and the dark within.
    Reply sent.



~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Test: 100 Loops, 25% Packet Loss

CLIENT OUTPUT:
--------------
PING 127.0.0.1   0 LOST
PING 127.0.0.1   1 0.000039
PING 127.0.0.1   2 LOST
PING 127.0.0.1   3 0.000058
PING 127.0.0.1   4 0.000064
PING 127.0.0.1   5 0.000067
PING 127.0.0.1   6 0.000070
PING 127.0.0.1   7 0.000072
PING 127.0.0.1   8 LOST
PING 127.0.0.1   9 0.000088
PING 127.0.0.1  10 0.000090
PING 127.0.0.1  11 0.000091
PING 127.0.0.1  12 LOST
PING 127.0.0.1  13 0.000103
PING 127.0.0.1  14 0.000102
PING 127.0.0.1  15 0.000100
PING 127.0.0.1  16 LOST
PING 127.0.0.1  17 LOST
PING 127.0.0.1  18 LOST
PING 127.0.0.1  19 0.000111
PING 127.0.0.1  20 LOST
PING 127.0.0.1  21 LOST
PING 127.0.0.1  22 0.000126
PING 127.0.0.1  23 0.000122
PING 127.0.0.1  24 0.000117
PING 127.0.0.1  25 0.000112
PING 127.0.0.1  26 0.000107
PING 127.0.0.1  27 LOST
PING 127.0.0.1  28 0.000120
PING 127.0.0.1  29 0.000117
PING 127.0.0.1  30 0.000112
PING 127.0.0.1  31 0.000109
PING 127.0.0.1  32 0.000105
PING 127.0.0.1  33 0.000101
PING 127.0.0.1  34 LOST
PING 127.0.0.1  35 0.000111
PING 127.0.0.1  36 0.000110
PING 127.0.0.1  37 0.000107
PING 127.0.0.1  38 0.000103
PING 127.0.0.1  39 0.000100
PING 127.0.0.1  40 0.000096
PING 127.0.0.1  41 0.000091
PING 127.0.0.1  42 0.000086
PING 127.0.0.1  43 0.000081
PING 127.0.0.1  44 0.000078
PING 127.0.0.1  45 0.000074
PING 127.0.0.1  46 LOST
PING 127.0.0.1  47 0.000089
PING 127.0.0.1  48 LOST
PING 127.0.0.1  49 0.000098
PING 127.0.0.1  50 0.000098
PING 127.0.0.1  51 0.000094
PING 127.0.0.1  52 0.000091
PING 127.0.0.1  53 0.000091
PING 127.0.0.1  54 0.000090
PING 127.0.0.1  55 0.000086
PING 127.0.0.1  56 LOST
PING 127.0.0.1  57 0.000100
PING 127.0.0.1  58 LOST
PING 127.0.0.1  59 0.000110
PING 127.0.0.1  60 0.000108
PING 127.0.0.1  61 0.000104
PING 127.0.0.1  62 LOST
PING 127.0.0.1  63 0.000114
PING 127.0.0.1  64 0.000112
PING 127.0.0.1  65 LOST
PING 127.0.0.1  66 0.000119
PING 127.0.0.1  67 0.000114
PING 127.0.0.1  68 LOST
PING 127.0.0.1  69 0.000122
PING 127.0.0.1  70 LOST
PING 127.0.0.1  71 0.000128
PING 127.0.0.1  72 0.000122
PING 127.0.0.1  73 0.000116
PING 127.0.0.1  74 LOST
PING 127.0.0.1  75 LOST
PING 127.0.0.1  76 LOST
PING 127.0.0.1  77 0.000122
PING 127.0.0.1  78 0.000140
PING 127.0.0.1  79 LOST
PING 127.0.0.1  80 0.000156
PING 127.0.0.1  81 LOST
PING 127.0.0.1  82 0.000162
PING 127.0.0.1  83 0.000153
PING 127.0.0.1  84 0.000150
PING 127.0.0.1  85 0.000151
PING 127.0.0.1  86 0.000154
PING 127.0.0.1  87 0.000157
PING 127.0.0.1  88 LOST
PING 127.0.0.1  89 0.000170
PING 127.0.0.1  90 LOST
PING 127.0.0.1  91 0.000179
PING 127.0.0.1  92 0.000185
PING 127.0.0.1  93 LOST
PING 127.0.0.1  94 LOST
PING 127.0.0.1  95 0.000190
PING 127.0.0.1  96 0.000195
PING 127.0.0.1  97 0.000184
PING 127.0.0.1  98 0.000174
PING 127.0.0.1  99 0.000166

COMPLETED:      72 packets received,    28 packets lost

SERVER OUTPUT:	Omitted due to space
--------------

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Test: 5 loops, 0% Packet loss

CLIENT OUTPUT:
--------------
PING 127.0.0.1   0 0.000041
PING 127.0.0.1   1 0.000067
PING 127.0.0.1   2 0.000087
PING 127.0.0.1   3 0.000104
PING 127.0.0.1   4 0.000105

COMPLETED:      5 packets received,     0 packets lost

SERVER OUTPUT:
--------------
Received from 127.0.0.1: The horse is the white of the eyes and the dark within.
    Reply sent.

Received from 127.0.0.1: The horse is the white of the eyes and the dark within.
    Reply sent.

Received from 127.0.0.1: The horse is the white of the eyes and the dark within.
    Reply sent.

Received from 127.0.0.1: The horse is the white of the eyes and the dark within.
    Reply sent.

Received from 127.0.0.1: The horse is the white of the eyes and the dark within.
    Reply sent.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Test: 5 loops, 100% Packet loss

CLIENT OUTPUT:
--------------
PING 127.0.0.1   0 LOST
PING 127.0.0.1   1 LOST
PING 127.0.0.1   2 LOST
PING 127.0.0.1   3 LOST
PING 127.0.0.1   4 LOST

COMPLETED:      0 packets received,     5 packets lost

SERVER OUTPUT:
--------------
Received from 127.0.0.1: The horse is the white of the eyes and the dark within.
    Reply not sent.

Received from 127.0.0.1: The horse is the white of the eyes and the dark within.
    Reply not sent.

Received from 127.0.0.1: The horse is the white of the eyes and the dark within.
    Reply not sent.

Received from 127.0.0.1: The horse is the white of the eyes and the dark within.
    Reply not sent.

Received from 127.0.0.1: The horse is the white of the eyes and the dark within.
    Reply not sent.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Test: 5 loops, 25% Packet Loss, 100ms delay

CLIENT OUTPUT:
--------------
PING 127.0.0.1   0 0.000036
PING 127.0.0.1   1 0.000058
PING 127.0.0.1   2 LOST
PING 127.0.0.1   3 LOST
PING 127.0.0.1   4 0.000088

COMPLETED:      3 packets received,     2 packets lost

SERVER OUTPUT:
--------------
Received from 127.0.0.1: The horse is the white of the eyes and the dark within.
    Reply sent.

Received from 127.0.0.1: The horse is the white of the eyes and the dark within.
    Reply sent.

Received from 127.0.0.1: The horse is the white of the eyes and the dark within.
    Reply not sent.

Received from 127.0.0.1: The horse is the white of the eyes and the dark within.
    Reply not sent.

Received from 127.0.0.1: The horse is the white of the eyes and the dark within.
    Reply sent.

