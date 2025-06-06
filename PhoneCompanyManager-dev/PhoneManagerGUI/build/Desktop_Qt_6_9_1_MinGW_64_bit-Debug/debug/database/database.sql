-- MySQL dump 10.13  Distrib 8.4.4, for Linux (x86_64)
--
-- Host: localhost    Database: db
-- ------------------------------------------------------
-- Server version	8.4.4

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Customers`
--

DROP TABLE IF EXISTS `Customers`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Customers` (
  `id` tinyint DEFAULT NULL,
  `full_name` varchar(21) DEFAULT NULL,
  `phone` varchar(13) DEFAULT NULL,
  `date_of_B` varchar(10) DEFAULT NULL,
  `date` varchar(0) DEFAULT NULL,
  `tariff_id` tinyint DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci ROW_FORMAT=DYNAMIC;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Customers`
--

LOCK TABLES `Customers` WRITE;
/*!40000 ALTER TABLE `Customers` DISABLE KEYS */;
INSERT INTO `Customers` VALUES (1,'Ethan Carter','123-456-7890','1992-04-15','',2),(2,'Sophia Mitchell','234-567-8901','1988-11-22','',1),(3,'Mason Bennett','345-678-9012','1995-07-08','',1),(4,'Ava Richardson','456-789-0123','1990-02-19','',2),(5,'Noah Henderson','567-890-1234','1985-09-30','',3),(6,'Olivia Brooks','678-901-2345','1998-12-25','',2),(7,'Liam Turner','789-012-3456','1993-06-14','',5),(8,'Emma Sullivan','890-123-4567','1987-10-07','',1),(9,'James Perry','901-234-5678','1999-03-28','',2),(10,'Charlotte Hayes','012-345-6789','1994-05-12','',6),(11,'Benjamin Foster','111-222-3333','1986-08-23','',6),(12,'Mia Collins','222-333-4444','1991-01-05','',6),(13,'Lucas Evans','333-444-5555','2000-07-17','',6),(14,'Amelia Reed','444-555-6666','1996-04-29','',6),(15,'Henry Walker','555-666-7777','1989-12-09','',3),(16,'Ivan Melnyk','+380501110001','1985-02-10','',1),(17,'Olena Shevchenko','+380501110002','1992-05-21','',2),(18,'Dmytro Petrenko','+380501110003','1988-03-15','',3),(19,'Kateryna Kovalenko','+380501110004','1995-08-10','',4),(20,'Oleh Tkachenko','+380501110005','1990-01-12','',5),(21,'Yulia Bondarenko','+380501110006','1987-11-20','',1),(22,'Serhii Kravchenko','+380501110007','1993-07-17','',2),(23,'Natalia Boyko','+380501110008','1991-04-04','',3),(24,'Andrii Moroz','+380501110009','1984-09-09','',4),(25,'Oksana Rudenko','+380501110010','1996-06-30','',5),(26,'Volodymyr Antonov','+380501110091','1990-03-02','',1),(27,'Maria Datsyuk','+380501110092','1992-10-10','',2),(28,'Pavlo Semenov','+380501110093','1989-05-05','',3),(29,'Diana Shulha','+380501110094','1994-08-08','',4),(30,'Roman Sokolov','+380501110095','1986-12-12','',5),(31,'Alina Yermolenko','+380501110096','1993-02-28','',1),(32,'Maksym Lytvyn','+380501110097','1991-06-06','',2),(33,'Tetiana Vovk','+380501110098','1985-07-07','',3),(34,'Yurii Zadorozhnyi','+380501110099','1988-09-09','',4),(35,'Lesia Honchar','+380501110100','1997-01-01','',5),(36,'Mykhailo Zakharchenko','+380501110011','1992-03-13','',1),(37,'Iryna Sydorenko','+380501110012','1986-07-25','',2),(38,'Taras Hnatyuk','+380501110013','1994-11-03','',3),(39,'Oksana Nesterenko','+380501110014','1990-02-19','',4),(40,'Vitalii Polishchuk','+380501110015','1989-04-27','',5),(41,'Anastasiia Holub','+380501110016','1993-06-18','',1),(42,'Denys Khomenko','+380501110017','1991-08-22','',2),(43,'Sofiia Lysenko','+380501110018','1987-12-05','',3),(44,'Bohdan Martynenko','+380501110019','1995-10-30','',4),(45,'Ievheniia Berezovska','+380501110020','1988-09-14','',5),(46,'Marta Panasenko','+380501110021','1996-05-01','',1),(47,'Ivan Slobodian','+380501110022','1992-07-07','',2),(48,'Viktoriia Chumak','+380501110023','1983-03-09','',3),(49,'Kyrylo Vozniuk','+380501110024','1990-10-17','',4),(50,'Liubov Kostiuk','+380501110025','1985-11-11','',5),(51,'Yevhen Melnychuk','+380501110026','1994-01-31','',1),(52,'Nadiia Dmytruk','+380501110027','1993-09-23','',2),(53,'Vladyslav Vasylenko','+380501110028','1986-06-06','',3),(54,'Inna Savytska','+380501110029','1995-12-25','',4),(55,'Artur Zahrebelnyi','+380501110030','1991-03-03','',5),(56,'Liliia Brovko','+380501110031','1989-08-18','',1),(57,'Borys Kovalchuk','+380501110032','1992-04-04','',2),(58,'Vira Taran','+380501110033','1990-06-11','',3),(59,'Oleksandr Duda','+380501110034','1996-02-20','',4),(60,'Yana Radchenko','+380501110035','1987-01-07','',5),(61,'Petro Dubovyi','+380501110036','1988-10-13','',1),(62,'Olha Senyk','+380501110037','1991-05-08','',2),(63,'Stanislav Romaniuk','+380501110038','1984-07-27','',3),(64,'Svitlana Nahorna','+380501110039','1993-11-19','',4),(65,'Artem Pavlenko','+380501110040','1985-12-31','',5),(66,'Tamara Shcherbak','+380501110041','1992-03-28','',1),(67,'Ihor Hladun','+380501110042','1986-09-05','',2),(68,'Maryna Tereshchenko','+380501110043','1994-06-16','',3),(69,'Vasyl Romanov','+380501110044','1990-10-01','',4),(70,'Alina Zhuk','+380501110045','1991-08-29','',5),(71,'Oleksii Lavrenko','+380501110046','1989-02-14','',1),(72,'Oriana Serdiuk','+380501110047','1995-05-13','',2),(73,'Danylo Bereza','+380501110048','1987-06-26','',3),(74,'Natalka Snisar','+380501110049','1994-01-19','',4),(75,'Vadym Korchak','+380501110050','1992-07-01','',5);
/*!40000 ALTER TABLE `Customers` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `CustomersUsers`
--

DROP TABLE IF EXISTS `CustomersUsers`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `CustomersUsers` (
  `id` varchar(0) DEFAULT NULL,
  `cust_id` varchar(0) DEFAULT NULL,
  `phone` varchar(0) DEFAULT NULL,
  `pass_hash` varchar(0) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci ROW_FORMAT=DYNAMIC;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `CustomersUsers`
--

LOCK TABLES `CustomersUsers` WRITE;
/*!40000 ALTER TABLE `CustomersUsers` DISABLE KEYS */;
/*!40000 ALTER TABLE `CustomersUsers` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Departments`
--

DROP TABLE IF EXISTS `Departments`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Departments` (
  `id` tinyint DEFAULT NULL,
  `department_name` varchar(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci ROW_FORMAT=DYNAMIC;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Departments`
--

LOCK TABLES `Departments` WRITE;
/*!40000 ALTER TABLE `Departments` DISABLE KEYS */;
INSERT INTO `Departments` VALUES (3,'Accounting & Finance'),(1,'Customer Support'),(5,'HR & Administration'),(2,'Sales Department'),(4,'Technical Support');
/*!40000 ALTER TABLE `Departments` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Employees`
--

DROP TABLE IF EXISTS `Employees`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Employees` (
  `id` tinyint DEFAULT NULL,
  `full_name` varchar(19) DEFAULT NULL,
  `department_id` tinyint DEFAULT NULL,
  `position_id` tinyint DEFAULT NULL,
  `hire_date` varchar(0) DEFAULT NULL,
  `salary` decimal(5,1) DEFAULT NULL,
  `phone` varchar(11) DEFAULT NULL,
  `email` varchar(31) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci ROW_FORMAT=DYNAMIC;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Employees`
--

LOCK TABLES `Employees` WRITE;
/*!40000 ALTER TABLE `Employees` DISABLE KEYS */;
INSERT INTO `Employees` VALUES (1,'John Carter',1,2,'',3500.0,'+1234567890','john.carter@example.com'),(2,'Emma Williams',2,4,'',4200.0,'+1234567891','emma.williams@example.com'),(3,'Liam Johnson',1,1,'',3100.0,'+1234567892','liam.johnson@example.com'),(4,'Olivia Brown',3,4,'',4800.0,'+1234567893','olivia.brown@example.com'),(5,'Noah Miller',2,2,'',3300.0,'+1234567894','noah.miller@example.com'),(6,'Sophia Davis',1,3,'',3900.0,'+1234567895','sophia.davis@example.com'),(7,'Mason Wilson',3,2,'',4100.0,'+1234567896','mason.wilson@example.com'),(8,'Ava Anderson',2,1,'',3050.0,'+1234567897','ava.anderson@example.com'),(9,'James Thomas',1,4,'',5000.0,'+1234567898','james.thomas@example.com'),(10,'Isabella Martinez',2,2,'',3450.0,'+1234567899','isabella.martinez@example.com'),(11,'Benjamin White',3,3,'',4300.0,'+1234567800','benjamin.white@example.com'),(12,'Mia Harris',1,1,'',3200.0,'+1234567801','mia.harris@example.com'),(13,'William Clark',2,4,'',5100.0,'+1234567802','william.clark@example.com'),(14,'Charlotte Rodriguez',3,2,'',3600.0,'+1234567803','charlotte.rodriguez@example.com'),(15,'Elijah Lewis',1,3,'',4000.0,'+1234567804','elijah.lewis@example.com'),(16,'Amelia Walker',2,1,'',3150.0,'+1234567805','amelia.walker@example.com'),(17,'Alexander Hall',3,4,'',4900.0,'+1234567806','alexander.hall@example.com'),(18,'Harper Allen',1,2,'',3550.0,'+1234567807','harper.allen@example.com'),(19,'Ethan Young',2,3,'',4250.0,'+1234567808','ethan.young@example.com'),(20,'Evelyn King',3,1,'',3000.0,'+1234567809','evelyn.king@example.com');
/*!40000 ALTER TABLE `Employees` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Messages`
--

DROP TABLE IF EXISTS `Messages`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Messages` (
  `id` tinyint DEFAULT NULL,
  `message_text` varchar(79) DEFAULT NULL,
  `date_time` varchar(0) DEFAULT NULL,
  `origin` tinyint DEFAULT NULL,
  `destination` varchar(13) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci ROW_FORMAT=DYNAMIC;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Messages`
--

LOCK TABLES `Messages` WRITE;
/*!40000 ALTER TABLE `Messages` DISABLE KEYS */;
INSERT INTO `Messages` VALUES (1,'Hello world!','',2,'+380990879320'),(2,'this is my second message to you','',2,'+380990879320'),(3,'this is my third message to you and i wanna test text collision','',2,'+380990879320'),(4,'this is my fourth message and i wanna test how DisplayLastMessage()const works!','',2,'+380990879320'),(5,'again','',2,'+380990879320'),(6,'and again','',2,'+380990879320'),(7,'and again third time!','',2,'+380990879320'),(8,'i hope this is my last message for checking','',2,'+380990879320'),(9,'blah blah blah','',2,'+380990879320'),(10,'HI THERE!','',2,'+380990879320'),(11,'fasdfasdf','',2,'+380990879320'),(12,'f','',2,'+380990879320'),(13,'c','',2,'+380990879320'),(14,'last','',2,'+380990879320'),(15,'d','',2,'+380990879320'),(16,'b','',2,'+380990879320'),(17,'v','',2,'+380990879320'),(18,'h','',2,'+380990879320'),(19,'Hello world!','',2,'+380990879320'),(20,'dfsd','',2,'+380990879320'),(21,'Hello moto','',2,'+380990879320'),(22,'That`s my last message to you','',2,'+380990879320'),(23,'testing finishing','',2,'+380990879320'),(24,'exit','',2,'+380990879320');
/*!40000 ALTER TABLE `Messages` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Payments`
--

DROP TABLE IF EXISTS `Payments`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Payments` (
  `id` varchar(0) DEFAULT NULL,
  `cust_id` varchar(0) DEFAULT NULL,
  `amount` varchar(0) DEFAULT NULL,
  `payment_type` varchar(0) DEFAULT NULL,
  `payment_date` varchar(0) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci ROW_FORMAT=DYNAMIC;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Payments`
--

LOCK TABLES `Payments` WRITE;
/*!40000 ALTER TABLE `Payments` DISABLE KEYS */;
/*!40000 ALTER TABLE `Payments` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Positions`
--

DROP TABLE IF EXISTS `Positions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Positions` (
  `id` tinyint DEFAULT NULL,
  `position_name` varchar(28) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci ROW_FORMAT=DYNAMIC;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Positions`
--

LOCK TABLES `Positions` WRITE;
/*!40000 ALTER TABLE `Positions` DISABLE KEYS */;
INSERT INTO `Positions` VALUES (4,'Administrator'),(1,'Call Center Operator'),(3,'Customer Service Supervisor'),(7,'Finance Analyst'),(6,'HR Manager'),(2,'Manager'),(8,'Network Engineer'),(5,'Technical Support Specialist');
/*!40000 ALTER TABLE `Positions` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Reports`
--

DROP TABLE IF EXISTS `Reports`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Reports` (
  `id` varchar(0) DEFAULT NULL,
  `cust_id` varchar(0) DEFAULT NULL,
  `description` varchar(0) DEFAULT NULL,
  `status` varchar(0) DEFAULT NULL,
  `date` varchar(0) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci ROW_FORMAT=DYNAMIC;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Reports`
--

LOCK TABLES `Reports` WRITE;
/*!40000 ALTER TABLE `Reports` DISABLE KEYS */;
/*!40000 ALTER TABLE `Reports` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Requests`
--

DROP TABLE IF EXISTS `Requests`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Requests` (
  `id` tinyint DEFAULT NULL,
  `cust_id` tinyint DEFAULT NULL,
  `request_type` varchar(18) DEFAULT NULL,
  `status` varchar(11) DEFAULT NULL,
  `date` varchar(0) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci ROW_FORMAT=DYNAMIC;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Requests`
--

LOCK TABLES `Requests` WRITE;
/*!40000 ALTER TABLE `Requests` DISABLE KEYS */;
INSERT INTO `Requests` VALUES (1,2,'Tariff Change','Current',''),(2,1,'Connection','In Progress',''),(3,2,'Disconnection','Completed',''),(4,3,'Tariff Change','In Progress',''),(5,1,'Technical Issue','Pending',''),(6,4,'Connection','In Progress',''),(7,2,'Tariff Change','Completed',''),(8,5,'Technical Issue','In Progress',''),(9,3,'Disconnection','Cancelled',''),(10,15,'Service Upgrade','Completed',''),(11,1,'Tariff Change','Completed',''),(12,27,'Technical Support','In Progress',''),(13,17,'SIM Replacement','Cancelled',''),(14,14,'Billing Issue','Completed',''),(15,6,'New Connection','Pending',''),(16,4,'Disconnection','Cancelled',''),(17,24,'Plan Migration','In Progress',''),(18,6,'Roaming Activation','Completed',''),(19,8,'New Connection','Completed',''),(20,28,'Disconnection','In Progress',''),(21,11,'Plan Migration','Cancelled',''),(22,14,'SIM Replacement','In Progress',''),(23,21,'Roaming Activation','Completed',''),(24,17,'Technical Support','In Progress',''),(25,30,'Tariff Change','Completed',''),(26,5,'Billing Issue','Completed',''),(27,22,'Tariff Change','In Progress',''),(28,3,'Technical Support','Pending',''),(29,10,'Disconnection','Completed',''),(30,13,'Service Upgrade','Cancelled',''),(31,16,'SIM Replacement','Completed',''),(32,26,'Roaming Activation','In Progress',''),(33,29,'Billing Issue','Cancelled',''),(34,2,'Tariff Change','Pending',''),(35,18,'Number Portability','In Progress',''),(36,12,'New Connection','Completed',''),(37,20,'Tariff Change','In Progress',''),(38,9,'Plan Migration','Completed',''),(39,7,'Technical Support','Cancelled',''),(40,30,'Disconnection','Pending',''),(41,11,'SIM Replacement','Completed',''),(42,19,'Billing Issue','In Progress',''),(43,23,'Service Upgrade','Pending',''),(44,15,'Roaming Activation','Completed',''),(45,4,'Tariff Change','Cancelled',''),(46,8,'Number Portability','Completed',''),(47,3,'Plan Migration','Completed',''),(48,28,'Tariff Change','Completed',''),(49,17,'New Connection','In Progress',''),(50,22,'Disconnection','Pending',''),(51,6,'Tariff Change','Completed',''),(52,1,'Billing Issue','In Progress',''),(53,26,'Technical Support','Completed',''),(54,10,'Tariff Change','Pending',''),(55,14,'Roaming Activation','Cancelled',''),(56,2,'Number Portability','Completed',''),(57,21,'Plan Migration','In Progress',''),(58,5,'Tariff Change','Completed',''),(59,25,'Service Upgrade','Cancelled',''),(60,13,'SIM Replacement','In Progress',''),(61,7,'Tariff Change','Completed',''),(62,24,'Technical Support','Pending',''),(63,27,'New Connection','Completed',''),(64,9,'Billing Issue','Completed',''),(65,19,'Plan Migration','Pending',''),(66,16,'Roaming Activation','Completed',''),(67,29,'Tariff Change','Cancelled',''),(68,12,'Tariff Change','In Progress',''),(69,18,'SIM Replacement','Completed',''),(70,20,'Technical Support','In Progress',''),(71,23,'New Connection','Pending',''),(72,25,'Billing Issue','Cancelled',''),(73,11,'Number Portability','Completed',''),(74,28,'Tariff Change','Completed',''),(75,8,'Tariff Change','In Progress',''),(76,3,'Service Upgrade','Completed',''),(77,15,'Roaming Activation','Pending','');
/*!40000 ALTER TABLE `Requests` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Tariffs`
--

DROP TABLE IF EXISTS `Tariffs`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Tariffs` (
  `id` tinyint DEFAULT NULL,
  `tariff_name` varchar(19) DEFAULT NULL,
  `daily_price` varchar(7) DEFAULT NULL,
  `monthly_price` varchar(6) DEFAULT NULL,
  `call_minutes` varchar(8) DEFAULT NULL,
  `internet_GB` varchar(6) DEFAULT NULL,
  `messages` smallint DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci ROW_FORMAT=DYNAMIC;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Tariffs`
--

LOCK TABLES `Tariffs` WRITE;
/*!40000 ALTER TABLE `Tariffs` DISABLE KEYS */;
INSERT INTO `Tariffs` VALUES (1,'Basic 100','2000.0','5.99','100.0','300.0',100),(2,'Standard 300','2000.0','12.99','300.0','300.0',100),(3,'Unlimited Calls','2000.0','19.99','-1.0','300.0',100),(4,'Family Plan','2000.0','29.99','1000.0','300.0',100),(5,'Business Pro','1880.0','39.99','2000.0','300.0',100),(6,'Youth Special','2000.0','7.99','200.0','300.0',100),(7,'Night Owl','2000.0','9.99','500.0','300.0',100),(8,'Weekend Unlimited','2000.0','14.99','-1.0','300.0',100),(9,'International Saver','2000.0','24.99','800.0','300.0',100),(10,'VIP Premium','2000.0','49.99','-1.0','300.0',100),(11,'New Tariff','2000.0','20.4','20.0','1000.0',100),(12,'NewTariff2','3000.0','43.0','200.0','300.0',100),(13,'asdfasdg','sadfadg','fdsfsd','asdfasdg','sdfasd',100);
/*!40000 ALTER TABLE `Tariffs` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Usage`
--

DROP TABLE IF EXISTS `Usage`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Usage` (
  `id` smallint DEFAULT NULL,
  `cust_id` tinyint DEFAULT NULL,
  `sms_send` tinyint DEFAULT NULL,
  `date` varchar(0) DEFAULT NULL,
  `used_minutes` decimal(4,2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci ROW_FORMAT=DYNAMIC;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Usage`
--

LOCK TABLES `Usage` WRITE;
/*!40000 ALTER TABLE `Usage` DISABLE KEYS */;
INSERT INTO `Usage` VALUES (1,2,0,'',20.00),(2,1,2,'',41.39),(3,1,60,'',13.28),(4,1,9,'',9.69),(5,1,23,'',8.16),(6,1,79,'',4.13),(7,1,91,'',36.09),(8,1,54,'',26.91),(9,1,4,'',28.98),(10,1,40,'',30.48),(11,1,99,'',17.38),(12,2,8,'',26.78),(13,2,55,'',12.54),(14,2,98,'',35.57),(15,2,48,'',32.07),(16,2,88,'',20.34),(17,2,95,'',0.40),(18,2,71,'',32.47),(19,2,55,'',38.78),(20,2,93,'',28.30),(21,2,20,'',42.12),(22,3,33,'',3.94),(23,3,64,'',16.16),(24,3,70,'',16.55),(25,3,98,'',9.05),(26,3,91,'',1.88),(27,3,59,'',44.79),(28,3,52,'',14.33),(29,3,83,'',27.74),(30,3,59,'',38.79),(31,3,16,'',38.51),(32,4,20,'',33.96),(33,4,65,'',11.05),(34,4,80,'',15.99),(35,4,77,'',12.23),(36,4,10,'',24.57),(37,4,12,'',41.57),(38,4,15,'',7.43),(39,4,81,'',32.84),(40,4,20,'',0.26),(41,4,75,'',22.70),(42,5,44,'',8.51),(43,5,59,'',44.45),(44,5,22,'',23.46),(45,5,70,'',30.57),(46,5,61,'',21.00),(47,5,72,'',30.11),(48,5,18,'',31.18),(49,5,0,'',21.47),(50,5,49,'',25.56),(51,5,66,'',36.41),(52,6,69,'',34.93),(53,6,28,'',24.24),(54,6,15,'',22.06),(55,6,56,'',29.42),(56,6,58,'',23.53),(57,6,50,'',5.42),(58,6,57,'',14.53),(59,6,17,'',1.89),(60,6,63,'',33.65),(61,6,65,'',18.11),(62,7,50,'',44.43),(63,7,56,'',48.37),(64,7,14,'',35.23),(65,7,13,'',40.22),(66,7,96,'',0.07),(67,7,66,'',39.15),(68,7,74,'',41.38),(69,7,72,'',32.44),(70,7,54,'',24.19),(71,7,72,'',49.76),(72,8,2,'',34.44),(73,8,50,'',33.26),(74,8,20,'',19.07),(75,8,61,'',33.60),(76,8,0,'',9.86),(77,8,25,'',33.10),(78,8,81,'',40.43),(79,8,57,'',30.24),(80,8,7,'',43.16),(81,8,82,'',43.89),(82,9,19,'',19.78),(83,9,71,'',14.81),(84,9,78,'',13.43),(85,9,27,'',25.09),(86,9,38,'',1.62),(87,9,18,'',29.46),(88,9,45,'',36.70),(89,9,30,'',35.02),(90,9,77,'',13.95),(91,9,80,'',46.34),(92,10,81,'',6.79),(93,10,13,'',27.71),(94,10,63,'',14.21),(95,10,25,'',1.62),(96,10,8,'',45.16),(97,10,9,'',22.17),(98,10,66,'',33.74),(99,10,51,'',23.99),(100,10,65,'',23.18),(101,10,44,'',22.42);
/*!40000 ALTER TABLE `Usage` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Users`
--

DROP TABLE IF EXISTS `Users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Users` (
  `id` tinyint DEFAULT NULL,
  `empl_id` tinyint DEFAULT NULL,
  `username` varchar(6) DEFAULT NULL,
  `pass_hash` varchar(64) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci ROW_FORMAT=DYNAMIC;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Users`
--

LOCK TABLES `Users` WRITE;
/*!40000 ALTER TABLE `Users` DISABLE KEYS */;
INSERT INTO `Users` VALUES (1,1,'admin','d74ff0ee8da3b9806b18c877dbf29bbde50b5bd8e4dad7a3a725000feb82e8f1'),(2,2,'admin2','unknown_value_please_contact_support');
/*!40000 ALTER TABLE `Users` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `sqlite_sequence`
--

DROP TABLE IF EXISTS `sqlite_sequence`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `sqlite_sequence` (
  `name` varchar(14) DEFAULT NULL,
  `seq` smallint DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci ROW_FORMAT=DYNAMIC;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `sqlite_sequence`
--

LOCK TABLES `sqlite_sequence` WRITE;
/*!40000 ALTER TABLE `sqlite_sequence` DISABLE KEYS */;
INSERT INTO `sqlite_sequence` VALUES ('Reports',0),('Payments',0),('CustomersUsers',0),('Departments',5),('Positions',8),('Employees',20),('Users',2),('Tariffs',13),('Requests',77),('Customers',75),('Usage',101),('Messages',24);
/*!40000 ALTER TABLE `sqlite_sequence` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2025-04-11 13:30:03
