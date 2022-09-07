-- MySQL dump 10.13  Distrib 5.7.30, for Linux (x86_64)
--
-- Host: localhost    Database: etu8
-- ------------------------------------------------------
-- Server version	5.7.30-0ubuntu0.16.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Current Database: `etu8`
--

CREATE DATABASE IF NOT EXISTS `etu8` DEFAULT CHARACTER SET utf8;

USE `etu8`;

--
-- Table structure for table `game`
--

DROP TABLE IF EXISTS `game`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `game` (
  `nomGame` varchar(20) NOT NULL,
  `idGame` int(11) NOT NULL AUTO_INCREMENT,
  `nbJoueur` int(11) DEFAULT NULL,
  `createurGame` varchar(21) NOT NULL,
  `statut` varchar(10) NOT NULL,
  `pwdGame` varchar(70) DEFAULT NULL,
  `nbJoueurMax` int(11) NOT NULL,
  PRIMARY KEY (`idGame`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `game`
--

LOCK TABLES `game` WRITE;
UNLOCK TABLES;

--
-- Table structure for table `joueur`
--

DROP TABLE IF EXISTS `joueur`;

CREATE TABLE `joueur` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `login` varchar(21) NOT NULL,
  `pwd` varchar(70) NOT NULL,
  `nomGameur` varchar(20) NOT NULL,
  `cible` int(11) DEFAULT NULL,
  `partieEnCour` int(11) DEFAULT NULL,
  `nbKill` int(11) DEFAULT NULL,
  `posX` double DEFAULT NULL,
  `posY` double DEFAULT NULL,
  `statut` varchar(10) DEFAULT NULL,
  `lastPollingDate` datetime DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;

LOCK TABLES `joueur` WRITE;
INSERT INTO `joueur` VALUES (1,'pierre','1eca51bbc1645204d27408c46a67e615e75980b9c3e34c05d3db0dca8077bfd0','Pierreletoutpuissant',0,0,0,5.1726463,-52.6565819,'deconnecte','2020-06-04 22:55:32'),(2,'manoa','991c4a598920d952deacd78aca527d5b4e961f296937d4566d419d32c32e6eff','manoaMoimeme',0,0,0,5.1726418,-52.6565894,'deconnecte',NULL),(3,'rethertherthtre','4f256b72010b50d0c8494849e735077debd74b944e51e22e510fff776ba0c8b0','erthrethreth',NULL,NULL,NULL,NULL,NULL,NULL,NULL);
UNLOCK TABLES;