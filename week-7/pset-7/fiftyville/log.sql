SELECT description
  FROM crime_scene_reports
 WHERE year = 2021
  AND month = 7
  AND day = 28
  AND street = 'Humphrey Street';

-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.
-- Littering took place at 16:36. No known witnesses.


SELECT name, transcript
  FROM interviews
 WHERE year = 2021
  AND month = 7
  AND day = 28;
-- Jose|“Ah,” said he, “I forgot that I had not seen you for some weeks. It is a little souvenir from the King of Bohemia in return for my assistance in the case of the Irene Adler papers.”
-- Eugene|“I suppose,” said Holmes, “that when Mr. Windibank came back from France he was very annoyed at your having gone to the ball.”
-- Barbara|“You had my note?” he asked with a deep harsh voice and a strongly marked German accent. “I told you that I would call.” He looked from one to the other of us, as if uncertain which to address.
-- Ruth|Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.
-- Eugene|I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on "Leggett Street" and saw the thief there withdrawing some money.
-- Raymond|As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.
-- Lily|Our neighboring courthouse has a very annoying rooster that crows loudly at 6am every day. My sons Robert and Patrick took the rooster to a city far, far away, so it may never bother us again. My sons have successfully arrived in Paris.


SELECT  account_number, amount
  FROM atm_transactions
 WHERE atm_location = 'Leggett Street'
  AND year = 2021
  AND month = 7
  AND day = 28
  AND transaction_type = 'withdraw';
-- 28500762|48
-- 28296815|20
-- 76054385|60
-- 49610011|50
-- 16153065|80
-- 25506511|20
-- 81061156|30
-- 26013199|35

SELECT * FROM people
  JOIN bank_accounts AS b
    ON b.person_id = people.id
  JOIN atm_transactions AS atm
  ON atm.account_number = b.account_number
 WHERE atm.atm_location = 'Leggett Street'
  AND atm.year = 2021
  AND atm.month = 7
  AND atm.day = 28
  AND atm.transaction_type = 'withdraw';

+--------+---------+----------------+-----------------+---------------+----------------+-----------+---------------+-----+----------------+------+-------+-----+----------------+------------------+--------+
|   id   |  name   |  phone_number  | passport_number | license_plate | account_number | person_id | creation_year | id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
+--------+---------+----------------+-----------------+---------------+----------------+-----------+---------------+-----+----------------+------+-------+-----+----------------+------------------+--------+
| 686048 | Bruce   | (367) 555-5533 | 5773159633      | 94KL13X       | 49610011       | 686048    | 2010          | 267 | 49610011       | 2021 | 7     | 28  | Leggett Street | withdraw         | 50     |
| 514354 | Diana   | (770) 555-1861 | 3592750733      | 322W7JE       | 26013199       | 514354    | 2012          | 336 | 26013199       | 2021 | 7     | 28  | Leggett Street | withdraw         | 35     |
| 458378 | Brooke  | (122) 555-4581 | 4408372428      | QX4YZN3       | 16153065       | 458378    | 2012          | 269 | 16153065       | 2021 | 7     | 28  | Leggett Street | withdraw         | 80     |
| 395717 | Kenny   | (826) 555-1652 | 9878712108      | 30G67EN       | 28296815       | 395717    | 2014          | 264 | 28296815       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     |
| 396669 | Iman    | (829) 555-5269 | 7049073643      | L93JTIZ       | 25506511       | 396669    | 2014          | 288 | 25506511       | 2021 | 7     | 28  | Leggett Street | withdraw         | 20     |
| 467400 | Luca    | (389) 555-5198 | 8496433585      | 4328GD8       | 28500762       | 467400    | 2014          | 246 | 28500762       | 2021 | 7     | 28  | Leggett Street | withdraw         | 48     |
| 449774 | Taylor  | (286) 555-6063 | 1988161715      | 1106N58       | 76054385       | 449774    | 2015          | 266 | 76054385       | 2021 | 7     | 28  | Leggett Street | withdraw         | 60     |
| 438727 | Benista | (338) 555-6650 | 9586786673      | 8X428L0       | 81061156       | 438727    | 2018          | 313 | 81061156       | 2021 | 7     | 28  | Leggett Street | withdraw         | 30     |
+--------+---------+----------------+-----------------+---------------+----------------+-----------+---------------+-----+----------------+------+-------+-----+----------------+------------------+--------+
--Thief is one of the above

SELECT people.id, people.name, people.phone_number,
f.id, f.origin_airport_id, f.destination_airport_id,f.hour, f.minute
  FROM people
  JOIN bank_accounts as b
    ON b.person_id = people.id
  JOIN atm_transactions as atm
    ON atm.account_number = b.account_number
  JOIN passengers as psg
    ON psg.passport_number = people.passport_number
  JOIN flights as f
    ON f.id =  psg.flight_id
 WHERE atm.atm_location = 'Leggett Street'
  AND atm.year = 2021
  AND atm.month = 7
  AND atm.day = 28
  AND atm.transaction_type = 'withdraw'
  AND f.year = 2021
  AND f.month = 7
  AND f.day = 29
ORDER BY f.hour, f.minute;

+--------+--------+----------------+----+-------------------+------------------------+------+--------+
|   id   |  name  |  phone_number  | id | origin_airport_id | destination_airport_id | hour | minute |
+--------+--------+----------------+----+-------------------+------------------------+------+--------+
| 686048 | Bruce  | (367) 555-5533 | 36 | 8                 | 4                      | 8    | 20     |
| 395717 | Kenny  | (826) 555-1652 | 36 | 8                 | 4                      | 8    | 20     |
| 467400 | Luca   | (389) 555-5198 | 36 | 8                 | 4                      | 8    | 20     |
| 449774 | Taylor | (286) 555-6063 | 36 | 8                 | 4                      | 8    | 20     |
| 458378 | Brooke | (122) 555-4581 | 53 | 8                 | 9                      | 15   | 20     |
| 514354 | Diana  | (770) 555-1861 | 18 | 8                 | 6                      | 16   | 0      |
+--------+--------+----------------+----+-------------------+------------------------+------+--------+
-- Thief've prepared to take the earliest flight out of Fiftyville on (29).
-- (Bruce, Kenny, Luca and Taylor) took the earliest flight.

SELECT *
  FROM airports
 WHERE id = 8
  OR id = 4;
+----+--------------+-----------------------------+---------------+
| id | abbreviation |          full_name          |     city      |
+----+--------------+-----------------------------+---------------+
| 4  | LGA          | LaGuardia Airport           | New York City |
| 8  | CSF          | Fiftyville Regional Airport | Fiftyville    |
+----+--------------+-----------------------------+---------------+
-- So, the thief escaped to (New York City)


SELECT *
  FROM bakery_security_logs AS bsl
  join people AS p
    ON p.license_plate = bsl.license_plate
 WHERE p.id
    IN ('686048', '395717', '467400', '449774')
    AND bsl.year = 2021
    AND bsl.month = 7
    AND bsl.day = 28
    AND bsl.hour = 10
    AND bsl.minute >= 15
    AND bsl.minute <= 25;

+-----+------+-------+-----+------+--------+----------+---------------+--------+-------+----------------+-----------------+---------------+
| id  | year | month | day | hour | minute | activity | license_plate |   id   | name  |  phone_number  | passport_number | license_plate |
+-----+------+-------+-----+------+--------+----------+---------------+--------+-------+----------------+-----------------+---------------+
| 263 | 2021 | 7     | 28  | 10   | 19     | exit     | 4328GD8       | 467400 | Luca  | (389) 555-5198 | 8496433585      | 4328GD8       |
| 261 | 2021 | 7     | 28  | 10   | 18     | exit     | 94KL13X       | 686048 | Bruce | (367) 555-5533 | 5773159633      | 94KL13X       |
+-----+------+-------+-----+------+--------+----------+---------------+--------+-------+----------------+-----------------+---------------+


SELECT p.id, p.name, pc.caller, pc.receiver,
pc.duration,pc.year, pc.month, pc.day
  from phone_calls AS pc
  JOIN people AS p
    ON p.phone_number = pc.caller
 WHERE pc.caller
    IN ('(389) 555-5198', '(367) 555-5533')
    AND duration < 60
    AND pc.year = 2021
    AND pc.month = 7
    AND pc.day = 28;

+--------+-------+----------------+----------------+----------+------+-------+-----+
|   id   | name  |     caller     |    receiver    | duration | year | month | day |
+--------+-------+----------------+----------------+----------+------+-------+-----+
| 686048 | Bruce | (367) 555-5533 | (375) 555-8161 | 45       | 2021 | 7     | 28  |
+--------+-------+----------------+----------------+----------+------+-------+-----+
-- Now, we can confirm that Bruce is the thief.


SELECT name
  FROM people
 WHERE phone_number = '(375) 555-8161';
+-------+
| name  |
+-------+
| Robin |
+-------+
-- So, The ACCOMPLICE is Robin