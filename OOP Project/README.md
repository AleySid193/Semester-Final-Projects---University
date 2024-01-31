# OOP_project
Project based on concepts of OOP principles

Welcome to the Vaccine Management System project! This C++ application is built on the principles of Object-Oriented Programming (OOP) to effectively manage the distribution, tracking, and administration of vaccines. The system is designed to streamline the vaccination process and ensure efficient management of vaccine-related data. The COVID-19 Vaccination Management System is designed to assist the government in efficiently handling the vaccination process for citizens. The system includes various modules for different user roles, ensuring a streamlined and organized approach to vaccine procurement, distribution, and administration.

# Features

**Patient Management:**
Register and manage patient details, including personal information and vaccination history.

**Vaccine Inventory:**
Keep track of available vaccines, their quantities, and expiration dates.

**Appointment Scheduling:**
Allow patients to schedule vaccination appointments and manage appointment details.

**OOP Concepts:**
Utilize concepts such as encapsulation, inheritance, and polymorphism to create a modular and maintainable codebase.

# Modules
## 1. Super Admin
The super admin has CRUD operations on all user accounts.
## 2. Admin
- Procures vaccines from local and international suppliers.
- Manages government-owned warehouse facilities.
- Establishes vaccination centers based on population ratios.
- Distributes vaccines to vaccination centers.
## 3. Doctor
- Assigned to vaccination centers.
- Assesses and logs citizens' vital stats during vaccinations.
## 4. Front Desk Officer (FDO)
- Interacts with citizens at vaccination centers.
- Checks eligibility and assigns the least busy counter for citizens.
## 5. Government Official
- Accesses reports on vaccination drive statistics.
- Filters and views data based on various criteria.

# Technical Details

## User Authentication:
All users require unique usernames and passwords, stored in encrypted form.
## Vaccine Information:
Stored in TXT files.
Includes vaccine type, name, ID, doses, price, batch ID, etc.
## Warehouse Information:
Includes warehouse name, location (latitude, longitude), and capacity.
## Batch Information:
Generated system IDs for items.
Prioritizes expired vaccines during dispatch.

# Installation
Clone the repository.
Install required dependencies.

# Usage
Run the application.
Access the relevant user interfaces based on user roles
