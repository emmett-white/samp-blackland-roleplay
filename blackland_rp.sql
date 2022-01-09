-- phpMyAdmin SQL Dump
-- version 5.0.2
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jan 09, 2022 at 03:23 AM
-- Server version: 10.4.13-MariaDB
-- PHP Version: 7.2.32

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `blackland_rp`
--

-- --------------------------------------------------------

--
-- Table structure for table `accounts`
--

CREATE TABLE `accounts` (
  `account_id` int(11) NOT NULL,
  `account_name` varchar(25) NOT NULL DEFAULT 'none',
  `account_password` varchar(64) NOT NULL DEFAULT 'none',
  `account_email` varchar(128) NOT NULL DEFAULT 'none'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `accounts`
--

INSERT INTO `accounts` (`account_id`, `account_name`, `account_password`, `account_email`) VALUES
(1, 'Emmett_White', 'nema.', 'fdsfd@gmail.com'),
(2, 'dekszy_16', 'nema ni ovaj deckic', 'fdsfs@gmail.com'),
(3, 'Test_User', '123456', 'fuck@off.com'),
(17, 'Dino_Mdfk', 'dinoistpapak', 'dino@mailer.com'),
(18, 'Frosty', 'jebeslozinku', 'fuck@off.com');

-- --------------------------------------------------------

--
-- Table structure for table `actors`
--

CREATE TABLE `actors` (
  `actor_id` int(11) NOT NULL,
  `actor_skin` mediumint(9) NOT NULL DEFAULT 0,
  `actor_animation` smallint(6) NOT NULL DEFAULT 0,
  `actor_vw` smallint(6) NOT NULL DEFAULT 0,
  `actor_interior` smallint(6) NOT NULL DEFAULT 0,
  `actor_x` float NOT NULL DEFAULT 0,
  `actor_y` float NOT NULL DEFAULT 0,
  `actor_z` float NOT NULL DEFAULT 0,
  `actor_a` float NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `actors`
--

INSERT INTO `actors` (`actor_id`, `actor_skin`, `actor_animation`, `actor_vw`, `actor_interior`, `actor_x`, `actor_y`, `actor_z`, `actor_a`) VALUES
(1, 60, 1, 0, 0, 1440.28, -976.015, 996.105, 0.914502),
(2, 29, 1, 0, 0, 1441.86, -974.863, 996.11, 84.3876),
(3, 294, 2, 0, 0, 1437.64, -989.311, 996.11, 347.026),
(4, 299, 2, 0, 0, 1437.73, -988.185, 996.105, 178.788),
(5, 76, 2, 0, 0, 1425.6, -980.073, 996.105, 91.179);

-- --------------------------------------------------------

--
-- Table structure for table `banned`
--

CREATE TABLE `banned` (
  `banned_id` int(11) NOT NULL,
  `banned_player` varchar(25) NOT NULL DEFAULT 'none',
  `banned_admin` varchar(25) NOT NULL DEFAULT 'none',
  `banned_reason` varchar(128) NOT NULL DEFAULT 'none'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Table structure for table `business`
--

CREATE TABLE `business` (
  `business_id` int(11) NOT NULL,
  `business_name` varchar(25) NOT NULL DEFAULT 'none',
  `business_owner` varchar(25) NOT NULL DEFAULT 'none',
  `business_type` smallint(6) NOT NULL DEFAULT 0,
  `business_price` int(11) NOT NULL DEFAULT 0,
  `business_locked` smallint(6) NOT NULL DEFAULT 0,
  `business_x` float NOT NULL DEFAULT 0,
  `business_y` float NOT NULL DEFAULT 0,
  `business_z` float NOT NULL DEFAULT 0,
  `business_intx` float NOT NULL DEFAULT 0,
  `business_inty` float NOT NULL DEFAULT 0,
  `business_intz` float NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `business`
--

INSERT INTO `business` (`business_id`, `business_name`, `business_owner`, `business_type`, `business_price`, `business_locked`, `business_x`, `business_y`, `business_z`, `business_intx`, `business_inty`, `business_intz`) VALUES
(1, 'Firma bez imena', 'Niko', 1, 255, 0, 635.981, -1495.43, 14.6559, 0, 0, 0),
(2, 'Firma bez imena', 'Niko', 2, 400, 0, 633.937, -1489.29, 14.59, 0, 0, 0),
(3, 'Firma bez imena', 'Niko', 2, 100000, 0, 626.403, -1484.39, 14.5373, 0, 0, 0),
(4, 'Firma bez imena', 'Niko', 1, 200, 0, 632.17, -1475.67, 14.4436, 0, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `characters`
--

CREATE TABLE `characters` (
  `char_id` int(11) NOT NULL,
  `char_name` varchar(25) NOT NULL DEFAULT 'none',
  `char_money` int(11) NOT NULL DEFAULT 10000,
  `char_level` int(11) NOT NULL DEFAULT 1,
  `char_skin` int(11) NOT NULL,
  `char_admin` int(11) NOT NULL DEFAULT 0,
  `char_admincode` mediumint(9) NOT NULL DEFAULT 0,
  `char_supporter` int(11) NOT NULL DEFAULT 0,
  `char_gold` int(11) NOT NULL DEFAULT 0,
  `char_bankmoney` int(11) NOT NULL DEFAULT 0,
  `char_bankaccount` smallint(6) NOT NULL DEFAULT 0,
  `char_orgid` int(11) NOT NULL DEFAULT 0,
  `char_leader` int(11) NOT NULL DEFAULT 0,
  `char_gunlicense` int(11) NOT NULL DEFAULT 0,
  `char_idcard` smallint(6) NOT NULL DEFAULT 0,
  `char_drugs` mediumint(9) NOT NULL DEFAULT 0,
  `char_weed` mediumint(9) NOT NULL DEFAULT 0,
  `char_mutedtime` mediumint(9) NOT NULL DEFAULT 0,
  `char_house` tinyint(4) NOT NULL DEFAULT -1
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `characters`
--

INSERT INTO `characters` (`char_id`, `char_name`, `char_money`, `char_level`, `char_skin`, `char_admin`, `char_admincode`, `char_supporter`, `char_gold`, `char_bankmoney`, `char_bankaccount`, `char_orgid`, `char_leader`, `char_gunlicense`, `char_idcard`, `char_drugs`, `char_weed`, `char_mutedtime`, `char_house`) VALUES
(1, 'Emmett_White', 34012, 4, 294, 4, 44, 0, 4, 10, 1, 1, 0, 1, 1, 10, 11, 0, 1),
(3, 'Test_User', 10000, 1, 294, 2, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0),
(15, 'udbhash', 6671, 1, 28, 1, 2811, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(17, 'Dino_Mdfk', 23400, 1, 299, 0, 0, 0, 0, -13490, 1, 0, 0, 0, 0, 0, 1, 0, 0),
(18, 'Frosty', 7581, 1, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `dealers`
--

CREATE TABLE `dealers` (
  `dealer_id` int(11) NOT NULL,
  `dealer_name` varchar(25) NOT NULL DEFAULT 'none',
  `dealer_skin` mediumint(9) NOT NULL DEFAULT 1,
  `dealer_x` float NOT NULL DEFAULT 0,
  `dealer_y` float NOT NULL DEFAULT 0,
  `dealer_z` float NOT NULL DEFAULT 0,
  `dealer_a` float NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `dealers`
--

INSERT INTO `dealers` (`dealer_id`, `dealer_name`, `dealer_skin`, `dealer_x`, `dealer_y`, `dealer_z`, `dealer_a`) VALUES
(1, 'fdgsg', 2, 642.326, -1493.82, 14.6386, 92.1932),
(2, 'dfadskfp', 5, 636.751, -1485.18, 14.5458, 47.1932),
(3, 'dsadddfadskfp', 66, 625.825, -1490.01, 14.5977, 137.193),
(4, 'dsdfds', 92, 622.64, -1479.04, 14.4798, 25.009);

-- --------------------------------------------------------

--
-- Table structure for table `houses`
--

CREATE TABLE `houses` (
  `house_id` int(11) NOT NULL,
  `house_desc` varchar(64) NOT NULL,
  `house_owner` varchar(25) NOT NULL,
  `house_owned` tinyint(1) NOT NULL,
  `house_locked` tinyint(1) NOT NULL,
  `house_price` int(11) NOT NULL,
  `house_extx` float NOT NULL,
  `house_exty` float NOT NULL,
  `house_extz` float NOT NULL,
  `house_intx` float NOT NULL,
  `house_inty` float NOT NULL,
  `house_intz` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `houses`
--

INSERT INTO `houses` (`house_id`, `house_desc`, `house_owner`, `house_owned`, `house_locked`, `house_price`, `house_extx`, `house_exty`, `house_extz`, `house_intx`, `house_inty`, `house_intz`) VALUES
(1, 'Test Opisa', 'Frosty', 1, 0, 2354, 644.52, -1489, 14.7683, 0, 0, 0),
(2, 'ne ulazi u kucu', 'Emmett_White', 1, 1, 10, 644.112, -1481.57, 14.7007, 0, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `server`
--

CREATE TABLE `server` (
  `server_record` int(11) NOT NULL DEFAULT 0,
  `hex` varchar(16) NOT NULL DEFAULT 'none'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `server`
--

INSERT INTO `server` (`server_record`, `hex`) VALUES
(470, 'FF0000AA');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `accounts`
--
ALTER TABLE `accounts`
  ADD PRIMARY KEY (`account_id`);

--
-- Indexes for table `actors`
--
ALTER TABLE `actors`
  ADD PRIMARY KEY (`actor_id`);

--
-- Indexes for table `banned`
--
ALTER TABLE `banned`
  ADD PRIMARY KEY (`banned_id`);

--
-- Indexes for table `business`
--
ALTER TABLE `business`
  ADD PRIMARY KEY (`business_id`);

--
-- Indexes for table `characters`
--
ALTER TABLE `characters`
  ADD PRIMARY KEY (`char_id`);

--
-- Indexes for table `dealers`
--
ALTER TABLE `dealers`
  ADD PRIMARY KEY (`dealer_id`);

--
-- Indexes for table `houses`
--
ALTER TABLE `houses`
  ADD UNIQUE KEY `house_id` (`house_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `accounts`
--
ALTER TABLE `accounts`
  MODIFY `account_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=19;

--
-- AUTO_INCREMENT for table `actors`
--
ALTER TABLE `actors`
  MODIFY `actor_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT for table `banned`
--
ALTER TABLE `banned`
  MODIFY `banned_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT for table `business`
--
ALTER TABLE `business`
  MODIFY `business_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT for table `characters`
--
ALTER TABLE `characters`
  MODIFY `char_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=19;

--
-- AUTO_INCREMENT for table `dealers`
--
ALTER TABLE `dealers`
  MODIFY `dealer_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT for table `houses`
--
ALTER TABLE `houses`
  MODIFY `house_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
