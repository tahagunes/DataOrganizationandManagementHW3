Create table person
(
		"personid" int NOT NULL,
		"name" varchar(100),
		"surname" varchar(100),
		"gender" varchar(10),
		"age" int,
		"city" varchar(15),
		"town" varchar(15),
		"address" varchar(100),
		CONSTRAINT "person_pk" PRIMARY KEY ("personid")
);

Create table HES
(
		 "hesCode" int NOT NULL,
		 "personId" int UNIQUE,
		 "health_situation" varchar(10),
		 "phoneNumber" varchar(11),
		 "vacInfo" varchar(15),
		 CONSTRAINT "hes_pk" PRIMARY KEY ("hesCode"),
		 CONSTRAINT "personId_fr" FOREIGN KEY ("personId") REFERENCES person("personid")match simple
		 ON UPDATE CASCADE ON DELETE CASCADE
);

Create table medcen
(
		"medcenId" int NOT NULL,
		"medcenName" varchar(100),
		"medcenCity" varchar(15),
		"medcentown" varchar(15),
		"medcenaddress" varchar(100),
		CONSTRAINT "medcen_pk" PRIMARY KEY ("medId")
);

Create table healthcare_pro
(
		"id" int NOT NULL,
		"name" varchar(15),
		"surname" varchar(15),
		"medcen_id" int,
		CONSTRAINT "healthcare_pro_pk" PRIMARY KEY ("id"),
		CONSTRAINT "medcen_id_fr" FOREIGN KEY ("medcen_id") REFERENCES medcen("medcenId")
);

Create table vaccine
(
		"vaccinename" varchar(15) NOT NULL,
		"country" varchar(15) NOT NULL,
		CONSTRAINT "vaccine_pk" PRIMARY KEY ("vaccinename")
);

Create table systemmm
(
		"personId" int,
		"healthcare_pro_id" int,
		"vaccinename" varchar(10),
		"vaccination_date" date,
		CONSTRAINT "healthcare_pro_id_fr" FOREIGN KEY ("healthcare_pro_id") REFERENCES healthcare_pro("id"),
		CONSTRAINT "vaccinename_fr" FOREIGN KEY ("vaccinename") REFERENCES vaccine("vaccinename")
);



insert into person("personid","name","surname","gender","age","city","town","address")
values(1,'osman taha','gunes','male',22,'karaman','merkez','karaman/merkez');
insert into HES("hesCode","personId","health_situation","phoneNumber","vacInfo")
values(1,1,'risk-free','05432661485','vaccinated');
insert into systemmm("personId","healthcare_pro_id","vaccinename","vaccination_date")
values(1,1,'Biontech','2021-06-24');

insert into person("personid","name","surname","gender","age","city","town","address")
values(2,'ahmet','gunes','male',62,'izmir','buca','karaman/buca');
insert into HES("hesCode","personId","health_situation","phoneNumber","vacInfo")
values(2,2,'risk-free','05437251485','vaccinated');
insert into systemmm("personId","healthcare_pro_id","vaccinename","vaccination_date")
values(2,1,'Biontech','2021-06-04');

insert into person("personid","name","surname","gender","age","city","town","address")
values(3,'zafer','yılmaz','male',47,'karaman','merkez','karaman/merkez');
insert into HES("hesCode","personId","health_situation","phoneNumber","vacInfo")
values(3,3,'risk-free','05534849876','vaccinated');
insert into systemmm("personId","healthcare_pro_id","vaccinename","vaccination_date")
values(3,2,'Sinovac','2021-06-24');

insert into person("personid","name","surname","gender","age","city","town","address")
values(4,'Ali','Aslan','male',17,'izmir','bornova','izmir/bornova');
insert into HES("hesCode","personId","health_situation","phoneNumber","vacInfo")
values(4,4,'risk-free','05430781485','vaccinated');
insert into systemmm("personId","healthcare_pro_id","vaccinename","vaccination_date")
values(4,1,'Sinovac','2021-05-14');

insert into person("personid","name","surname","gender","age","city","town","address")
values(5,'ozan','bozkır','male',74,'izmir','buca','karaman/buca');
insert into HES("hesCode","personId","health_situation","phoneNumber","vacInfo")
values(5,5,'risk-risky','05437251485','unvaccinated');

insert into healthcare_pro("id","name","surname","medcen_id")
values(1,'osman','aslan',1);
insert into healthcare_pro("id","name","surname","medcen_id")
values(2,'taha','küçük',2);

insert into medcen("medcenId","medcenName","medcenCity","medcentown","medcenaddress")
values(1,'Karaman Hospital','karaman','merkez','karaman/merkez karaman hospital' );
insert into medcen("medcenId","medcenName","medcenCity","medcentown","medcenaddress")
values(2,'Dokuz Eylül University Hospital','izmir','balçova','izmir/balçova dokuz eylül university hospital' );

insert into vaccine("vaccinename","country")
values('Biontech','Germany');
insert into vaccine("vaccinename","country")
values('Sinovac','China');

