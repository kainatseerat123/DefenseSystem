#include<iostream>
#include<fstream>
#include<string>
#include<cctype>
#include<cmath>
using namespace std;

// GLOBAL VARIABLE
string specific_countries[12]={"pakistan","saudiarabia","turkey","china","us","iran","qatar","india","uae","russia","palestine","israel"};

// POLYMORPHISM
class basecase1{
	public:
		virtual void userCityInfo()=0;
		virtual void enemyCityInfo()=0;
		virtual void distanceCalculate()=0;
};

class case1:public basecase1{
	private:
		string user_country[1];
	    string user_city;
	    string enemy_country[1];
	    string enemy_city;
		string user_specificcountries[12];
	    string enemy_specificcountries[12];
	    string pakistan[12];
	    string iran[16];
	    string china[12];
	    string turkey[12];
	    string russia[12];
		string saudiarabia[12];
	    string qatar[12];
	    string india[12];
	    string us[12];
	    string uae[12];
	    string palestine[12];
	    string israel[12];
	    bool verify_user_country=false;
	    bool verify_user_city=false;
	    bool verify_enemy_country=false;
	    bool verify_enemy_city=false;
	    bool verify_coordinates=false;
	    double user_city_latitude;
		double user_city_longitude;
		double enemy_city_latitude;
		double enemy_city_longitude;
		double distance;
    
    public:
    
	    case1(): user_specificcountries{"pakistan", "saudiarabia", "turkey", "china", "us", "iran", "qatar", "india", "uae", "russia","palestine","israel"},
		enemy_specificcountries{"pakistan","saudiarabia","turkey","china","us","iran","qatar","india","uae","russia","palestine","israel"},
		pakistan{"islamabad","rawalpindi","peshawar","faisalabad","karachi","lahore","sialkot","quetta","sargodha","gawadar","multan","gilgit"},
		iran{"tehran","tabriz","yazd","isfahan","shiraz","kashan","kerman","ardabil","rasht","hamedan","ahvaz","mashhad","khorramabad","bushehr","qazvin","babol"},
		china{"beijing","shanghai","chongqing","hangzhou","shenyang","tianjin","nanchang","guangzhou","chengdu","shenzhen","wuhan","qingdao"},
		turkey{"istanbul","ankara","izmir","bursa","adana","gaziantep","konya","antalya","kayseri","diyarbakir","samsun","edirne"},
		russia{"moscow","tomsk","novosibirsk","krasnodar","kazan","samara","volgograd","yekaterinburg","omsk","irkutsk","astrakhan","ufa"},
		saudiarabia{"madina","makkah","riyadh","jeddah","dammam","taif","al-jubail","tabuk","al-qatif","dhahran","abha","al-khobar"},
		qatar{"doha","al khor","mesaieed","dukhan","al kharrara","al-kiranah","fuwayrit","dakhira","al waab","izghawa"},
		india{"mumbai","delhi","hyderabad","kolkata","bengaluru","lucknow","chandigarh","ahmedabad","surat","visakhapatnam","pune","bhopal"},
		us{"new york","chicago","los angeles","houston","san diego","washington","california","phoenix","san jose","san antonio","jacksonville", "las vegas"},
		uae{"dubai","sharjah","ajman","fujairah","kalba","khatt","hatta","ghiyathi","masfut","lahbab","ghayl","ghalilah"},
		palestine{"khan yunis","gaza","rafah","hebron","north gaza","jabalia","beit hanoun","nablus","qabatiya","qalqilya","abu dis","tubas"},
		israel{"afula","arad","ashdod","bat yam","haifa","kafr qasim","lod","rahat","ramla","tayibe","dimona","lod"}
		{
			//initialization of list in constructor
		}
		
		
		
		void userCityInfo(){
			cout<<"YOU SELECTED OFFENSIVE STRIKE STRATEGY... \n"<<endl;
		    cout<<"Enter The Name Of Your Country: ";
		    cin>>user_country[0];
		    
	    	for(int i=0;i<user_country[0].length();i++){	//// CASE SENSITIVE
	    	
				if(isupper(user_country[0][i])){
					
					user_country[0][i]=tolower(user_country[0][i]);
				}
			}
		
	    
		    while (verify_user_country==false){
		        for(int i=0 ; i<12 ;i++){
		            if(user_country[0] == user_specificcountries[i]){
		                verify_user_country=true;
				        cout<<"Data Of This Country Is Available In Our Database \n";
				        break;
		            }
		        }
		
		        if(verify_user_country==false){
		            cout<<"You Entered an Invalid Country Name\n\t\t\t OR \nThe Data Of This Country Is Not Available In Our Database"<<endl;
		            cout<<"\a\nEnter a Valid Country Name : "<<endl;
				    cin>>user_country[0];
		        }
		    }	
	
		    cout<<"Enter City Of "<<user_country[0]<<" : ";
		    cin>>user_city;
		    
		    for(int i=0;i<user_city.length();i++){	//// CASE SENSITIVE
		    
				if(isupper(user_city[i])){
					
					user_city[i]=tolower(user_city[i]);
				}
			}
	    
		    while (verify_user_city==false){
		        for(int i=0 ; i<10 ;i++){
		            if(user_city == pakistan[i]||user_city == iran[i]||user_city == china[i]||user_city == turkey[i]||user_city == russia[i]||user_city == saudiarabia[i]
					||user_city == qatar[i]||user_city == india[i]||user_city == uae[i]||user_city == us[i]||user_city == palestine[i]||user_city == israel[i]){
		                verify_user_city=true;
				        cout<<"Data Of This City Is Available In Our Database \n";
				        break;
		            }
		        }
		
		        if(verify_user_city==false){
		            cout<<"You Entered an Invalid Country Name\n\t\t\t OR \nThe Data Of This City Is Not In Our Database"<<endl;
		            cout<<"\a\nEnter a Valid City Name : "<<endl;
				    cin>>user_city;
		        }
		    }
		
		    cout<<"\n\nEnter The Coordinates Of "<<user_city<<" ........."<<endl;
		    
		    for(int i=0;i<1;i++){
				cout<<"Enter The Latitudes Of "<<user_city<<" : ";  		
		    	for(int i=0;i<1;i++){            //////// cc type  /////////
		    		cin>>user_city_latitude; 
		    		if(user_city_latitude==isalpha(user_city_latitude)){
		    		cout<<"\nInput Is Invalid"<<endl;
		    		cout<<"Enter Again :";
					cin.clear();
		    		cin.ignore();
		    		i--;
					}
				}
		
				if (user_city_latitude<-90||user_city_latitude>90){
					cout<<"Your Entered Invalid Latitudes Of "<<user_city<<endl;
					cout<<"Because Latitude Must Be Greater Than -90 and Less Than or Equal 90"<<endl;
					cout<<"\n\aSo Enter Again"<<endl;
					i--;
				}
		
			}
		
			for(int i=0;i<1;i++){
				cout<<"Enter The Longitude Of "<<user_city<<" : ";
				for(int i=0;i<1;i++){            //// cc type ///
		    		cin>>user_city_longitude; 
		    		if(user_city_longitude==isalpha(user_city_longitude)){
		    		cout<<"\nInput Is Invalid"<<endl;
		    		cout<<"Enter Again :";
					cin.clear();
		    		cin.ignore();
		    		i--;
					}
				}
		
				if (user_city_longitude<-180||user_city_longitude>180){
					cout<<"Your Entered Longitudes Of Is Invalid"<<user_city<<endl;
					cout<<"Because Longitudes Must Be Greater Than -180 And Less Than or Equal To 180"<<endl;
					cout<<"\aSo Enter Again"<<endl;
					i--;
				}
			}
		}
	
	
	
		void enemyCityInfo(){
			cout<<"\nEnter The Name Of Enemy Country : ";
	    	cin>>enemy_country[0];
	    	
	    	for(int i=0;i<user_city.length();i++){	//// CASE SENSITIVE
	    	
				if(isupper(enemy_country[0][i])){
					
					enemy_country[0][i]=tolower(enemy_country[0][i]);
				}
			}
		    
		    while (verify_enemy_country==false){
		        for(int i=0 ; i<12 ;i++){
		            if(enemy_country[0] == enemy_specificcountries[i]){
		                verify_enemy_country=true;
				        cout<<"Data Of This Country Is Available In Our Database\n";
				        break;
		            }
		        }
		
		        if(verify_enemy_country==false){
		            cout<<"You Entered an Invalid Country Name OR The Data Of This Country Is Not Available In Our Database"<<endl;
		            cout<<"\aEnter a Right Country Name : "<<endl;
				    cin>>enemy_country[0];
		        }
		    }
		    
		    cout<<"Enter City Of "<<enemy_country[0]<<" : ";
		    cin>>enemy_city;
		    
		    for(int i=0;i<user_city.length();i++){	//// CASE SENSITIVE
	    	
				if(isupper(enemy_city[i])){
					
					enemy_city[i]=tolower(enemy_city[i]);
				}
			}
		    		    
		    while (verify_enemy_city==false){
		        for(int i=0 ; i<12 ;i++){
		            if(enemy_city == pakistan[i]||enemy_city == iran[i]||enemy_city == china[i]||enemy_city == turkey[i]||enemy_city == russia[i]||enemy_city == saudiarabia[i]||enemy_city == qatar[i]||enemy_city == india[i]||enemy_city == uae[i]||enemy_city == us[i] ||enemy_city == palestine[i] ||enemy_city == israel[i]){
		                verify_enemy_city=true;
				        cout<<"Data Of This City Is Available In Our Database\n";
				        break;
		            }
		        }
		
		        if(verify_enemy_city==false){
		            cout<<"You Entered an Invalid City Name OR The Data Of This City Is Not Available In Our Database"<<endl;
		            cout<<"\aEnter a Right City Name : "<<endl;
				    cin>>enemy_city;
		        }
		    }    
		    
			cout<<"\nEnter The Coordinates Of "<<enemy_city<<" ........."<<endl;
			
		    for(int i=0;i<1;i++){
				cout<<"Enter The Latitude Of "<<enemy_city<<" : ";
				for(int i=0;i<1;i++){            //////// cc type  /////////
		    		cin>>enemy_city_latitude; 
		    		if(enemy_city_latitude==isalpha(enemy_city_latitude)){
		    		cout<<"\nInput Is Invalid"<<endl;
		    		cout<<"Enter Again :";
					cin.clear();
		    		cin.ignore();
		    		i--;
					}
				}
		
				if (enemy_city_latitude<-90||enemy_city_latitude>90){
					cout<<"Your Entered Latitude Of Is Invalid"<<user_city<<endl;
					cout<<"Because Latitude Must Be Greater Than -90 And Less Than or Equal To 90"<<endl;
					cout<<"\aSo Enter Again"<<endl;
					i--;
				}
		
			}
		
			for(int i=0;i<1;i++){
				cout<<"Enter The Longitude Of "<<enemy_city<<" : ";
				for(int i=0;i<1;i++){            //////// cc type  /////////
		    		cin>>enemy_city_longitude; 
		    		if(enemy_city_longitude==isalpha(enemy_city_longitude)){
		    		cout<<"\nInput Is Invalid"<<endl;
		    		cout<<"Enter Again :";
					cin.clear();
		    		cin.ignore();
		    		i--;
					}
				}
		
				if (enemy_city_longitude<-180||enemy_city_longitude>180){
					cout<<"Your Entered Invalid Longitudes of "<<user_city<<endl;
					cout<<"Because Longitudes Must Be Greater Than -180 and Less Than or Equal to 180"<<endl;
					cout<<"\aSo Enter Again"<<endl;
					i--;
				}
			}
				
		}
		
		
	 	void distanceCalculate();
	 	// FRIEND FUNCTION
	 	friend double formula_for_distance(double latitude_1,double longitude_1,double latitude_2,double longitude_2);
	 
};

class Missile {
public:
    string name;
    double range;
    string mach_speed;
    double speed;
    string warhead;
    string status;
    string type;
    
    
	Missile(const string& n = "", double r = 0,const string& mach_s = "", double s = 0, const string& w = "", const string& st = "", const string& t = "")
        : name(n), range(r), mach_speed(mach_s), speed(s), warhead(w), status(st), type(t) {}
        
    
};

//POLYMORPHISM
class baseattackingMissile{
	public:
		virtual void Attacking_missiles(double dist,string user_country[0],string specific_countries[])=0;
		
};

class attackingMissile : public baseattackingMissile{
	public:
		Missile pakistan[9];
		Missile saudiarabia[6];
		Missile turkey[8];
		Missile china[13];
		Missile us[9];
		Missile iran[12];
		Missile qatar[4];
		Missile india[23];
		Missile uae[5];
		Missile russia[7];
		Missile palestine[7];
		Missile israel[7];
	public:
		attackingMissile():pakistan {{"Babur-3",450,"Mach 2.0",2470,"Single WAR-Head","Operational","Cruise missile"},
									{"Ghaznavi",290,"Mach 5",6174,"Single WAR-Head","Operational","Short Range Ballistic missile"},
									{"Shaheen I",750,"Mach 5",6174,"Single WAR-Head","Operational","Short Range Ballistic missile"},
									{"Shaheen II",1500,"Mach 5",6174,"Multiple WAR-Head","Operational","Mid Range Ballistic missile"},
									{"Ababeel",2200,"Mach 5",6174,"Multiple WAR-Head","Operational","Intermediate Range Ballistic missile"},
									{"Nasr",70,"Mach 5",6174,"Single WAR-Head","Operational","Short Range Ballistic missile"},
									{"Ra'ad (Hatf VIII)",700,"Mach 0.7",990,"Single WAR-Head","Operational","Air Launched-Cruise Missile"},
									{"Babur (Hatf VII)",700,"Mach 0.7",990,"Single WAR-Head","Operational","Ground Launched-Cruise Missile"},
									{"Shaheen III",700,"Mach 0.7",990,"Single WAR-Head","Operational","ballistic"}},
									
						saudiarabia{{"DF-3 (Al-Samoud)", 2600, "Mach 5", 132,"Multiple WAR-Head", "Intermediate-range ballistic missile"},
									{"DF-21 (Al-Watah)", 1500, "Mach 5", 4231,"Multiple WAR-Head", "Medium-range ballistic missile"},
    								{"DF-61 (Al-Hussein)", 600, "Mach 5", 4121,"Single WAR-Head", "Short-range ballistic missile"},
									{"Patriot Missile System", 150, "Mach 5", 431,"Single WAR-Head", "Surface-to-air missile system"},
									{"Al-Sadiq (Skyguard)", 3, "Supersonic",2411,"Single WAR-Head", "Short-range air defense system"},
									{"CSS-2 (Dong Feng-3)", 2800, "Supersonic", 453, "Multiple WAR-Head","Intermediate-range ballistic missile"}},
									
							  turkey{{"Bora (KAAN)", 280, "Supersonic", 345,"Single WAR-Head", "Tactical ballistic missile"},
							  		{"Atmaca", 220, "Subsonic", 2600,"Single WAR-Head", "Anti-ship cruise missile"},
									{"SOM (Standoff Missile)", 250, "Subsonic", 534,"Single WAR-Head","Operational", "Air-launched cruise missile"},
									{"Hisar-A", 0, "Supersonic", 0,"Single WAR-Head","Operational", "Short-range air defense missile system"},
									{"Hisar-O", 0, "Supersonic", 0, "Multiple WAR-Head","Operational","Medium-range air defense missile system"},
									{"Roketsan T-122 Sakarya", 300, "Supersonic", 2321, "Single WAR-Head","Operational","Tactical ballistic missile"},
									{"J600T Yildirim", 280, "Supersonic", 3421, "Single WAR-Head","Operational","Tactical ballistic missile"},
									{"BMC Tacir", 200, "Hypersonic",2342, "Single WAR-Head","Operational", "Precision-guided stand-off missile"}},
									
							   china{{"DF-41 (Dongfeng-41)", 12000, "Hypersonic", 2600, "Multiple WAR-Head", "Intercontinental Ballistic Missile (ICBM)"},
							   		{"DF-31 (Dongfeng-31)", 11200, "Hypersonic",3453, "Multiple WAR-Head", "Intercontinental Ballistic Missile (ICBM)"},
									{"DF-26 (Dongfeng-26)", 3000, "Hypersonic", 4000, "Multiple WAR-Head", "Intermediate-range Ballistic Missile (IRBM)"},
									{"DF-21D (Dongfeng-21D)", 1500, "Hypersonic", 1700, "Multiple WAR-Head","Operational","Anti-ship Ballistic Missile (ASBM)"},
									{"DF-17 (Dongfeng-17)", 1500, "Hypersonic", 2000, "Multiple WAR-Head","Operational","Hypersonic Glide Vehicle (HGV)"},
    								{"DF-16 (Dongfeng-16)", 800, "Hypersonic", 1000, "Single WAR-Head", "Short-range Ballistic Missile (SRBM)"},
									{"DF-15 (Dongfeng-15)", 600, "Hypersonic", 900, "Single WAR-Head", "Short-range Ballistic Missile (SRBM)"},
									{"CJ-10 (Changjian-10)", 1500, "Subsonic", 3453, "Multiple WAR-Head", "Land-attack cruise missile"},
									{"YJ-18", 500, "Supersonic",321, "Single WAR-Head", "Anti-ship cruise missile"},
   									{"HQ-9", 200, "Hypersonic",3453,  "Single WAR-Head","Long-range surface-to-air missile system"},
									{"DH-10 (HongNiao)", 1500, "Subsonic", 2500, "Multiple WAR-Head", "Land-attack cruise missile"},
									{"CJ-20 (Changjian-20)", 1500, "Subsonic", 2500, "Multiple WAR-Head", "Land-attack cruise missile"}},
									
								us{{"AIM-120(AMRAAM)", 180, "Mach 4",3066,"Single WAR-Head","Operational","Air-to-Air Missile"},
								  {"AGM-114 Hellfire", 8, "Subsonic",3066,"Single WAR-Head","Operational","Air-to-ground missile"},
								  {"Tomahawk", 1600, "Subsonic",3066, "Multiple WAR-Head","Operational", "Land-attack cruise missile"},
				   				  {"Minuteman III", 13000, "Hypersonic (reentry speed)",3066, "Multiple WAR-Head","Operational","Intercontinental Ballistic Missile (ICBM)"},
								  {"BGM-71 TOW", 4.5, "Subsonic",3066,"Single WAR-Head","Operational","Anti-tank guided missile"},
								  {"Patriot Missile System (MIM-104)", 160, "Hypersonic",3066,"Single WAR-Head","Operational", "Surface-to-air missile system"},
				    			  {"Standard Missile (SM-2, SM-3, SM-6)", 0, "Varies by variant",3066,"Single WAR-Head","Operational","Naval surface-to-air and anti-ballistic missile"},
								  {"AGM-158 Joint Air-to-Surface Standoff Missile (JASSM)", 370, "Subsonic",3066,"Single WAR-Head","Operational","Air-launched cruise missile"},
								  {"RIM-174 S Missile (ERAM)", 500, "Hypersonic",3066,"Single WAR-Head","Operational", "Extended range surface-to-air missile"}},
								  
							  	iran{{"Soumar", 700, "Subsonic",2470,"Single WAR-Head","operational", "Cruise missile"},
							  	{"Khorramshahr", 2000, "subsonic",3066,"Multiple WAR-Head","operational", "Medium-range ballistic missile"},
								{"Emad", 1700, "subsonic",3066,"operational","Multiple WAR-Head","Medium-range ballistic missile"},
								{"Zolfaghar", 700, "subsonic",3066,"Single WAR-Head","operational", "Short-range ballistic missile"},
								{"Fateh-110 (Naze'at)", 300, "Supersonic",3066,"Single WAR-Head","operational", "Short-range ballistic missile"},
								{"Qiam", 800, "supersonic",3066,"Single WAR-Head","operational", "Short-range ballistic missile"},
								{"Sejjil-1", 2000, "subsonic",3066,"Multiple WAR-Head","operational", "Ballistic missiles"},
								{"Sejjil-2", 2000, "subsonic",3066,"Multiple WAR-Head","operational", "Ballistic missiles"},
								{"Shahab-1", 1000, "subsoni",3066,"Multiple WAR-Head","operational", "Ballistic missiles"},
								{"Shahab-2", 1500, "Supersonic",3066,"Multiple WAR-Head","operational", "Ballistic missiles"},
								{"Shahab-3", 2000, "Supersonic",3066,"Multiple WAR-Head","operational", "Ballistic missiles"}},
								
								qatar{{"NASAMS ", 10000, "Varies",3066,"Multiple WAR-Head","Operational", "Surface-to-air missile system"},
									{"Patriot Missile System (MIM-104)", 0, "Varies",3066,"Single WAR-Head","Operational", "Surface-to-air missile system"},
									{"Javelin", 4, "Supersonic",3066,"Single WAR-Head","Operational","Man-portable, fire-and-forget infrared-guided missile"},
									{"Harpoon", 120, "Subsonic",3066,"Single WAR-Head", "operational", "Anti-ship missile"}},
									  
								india{{"Prithvi I", 600, "Subsonic",700,"Single WAR-Head","Operational", "Tactical surface-to-surface ballistic missile"},
									{"Prithvi II", 600, "Subsonic",2000,"Single WAR-Head","Operational", "Tactical surface-to-surface ballistic missile"},
									{"Prithvi III", 600, "Subsonic",2000,"Single WAR-Head","Operational", "Tactical surface-to-surface ballistic missile"},
									{"Agni-I", 5000, "Subsonic",3066,"Multiple WAR-Head","operational","Intermediate-range ballistic missile (IRBM)"},
									{"Agni-II", 5000, "Subsonic",200,"Multiple WAR-Head","operational", "Intercontinental ballistic missile (ICBM)"},
									{"Agni-III", 5000, "Subsonic",600,"Multiple WAR-Head","operational","Intermediate-range ballistic missile (IRBM)"},
									{"Agni-IV", 5000, "Subsonic",3066,"Multiple WAR-Head","Operational","Intercontinental ballistic missile (ICBM)"},
									{"Agni-V", 5000, "Subsonic",3066,"Multiple WAR-Head","Operational","Intermediate-range ballistic missile (IRBM)"},
									{"Agni-VI", 5000, "Subsonic",3066,"Multiple WAR-Head","Operational","Intercontinental ballistic missile (ICBM)"},
									{"Akash Mk1", 25, "Supersonic",700,"Single WAR-Head","Operational", "Medium-range surface-to-air missile"},
									{"Akash Mk2", 25, "Supersonic",3066,"Single WAR-Head","Operational","Medium-range surface-to-air missile"},
									{"BrahMos Land-launched", 500, "Supersonic",2000,"Single WAR-Head","Operational", "Supersonic cruise missile"},
									{"BrahMos Ship-launched", 500, "Supersonic",3066,"Single WAR-Head","operational","Supersonic cruise missile"},
									{"BrahMos Air-launched", 500, "Supersonic",3066,"Single WAR-Head","Operational","Supersonic cruise missile"},
									{"Dhanush", 350, "Subsonic",3066,"Single WAR-Head","Operational","Ship-launched ballistic missile"},
									{"Prahaar", 150, "Supersonic",3066,"Single WAR-Head","Operational","Tactical surface-to-surface ballistic missile"},
									{"Nirbhay", 1000, "Subsonic",3066,"Multiple WAR-Head","operational","Long-range subsonic cruise missile"}},
						
								  uae{{"Al Mursad", 300, "Mach 3", 1800,"Single WAR-Head","Operational", "Surface-to-air missile system"},
								  	{"Yabhon United 40", 500, "Subsonic", 800,"Single WAR-Head","Operational", "Cruise missile"},
					    			{"Al Tariq", 1000, "Mach 4", 2500,"Single WAR-Head","Under Development", "Ballistic missile"},
									{"Qasem", 120, "Supersonic", 1600,"Single WAR-Head","Operational", "Anti-ship cruise missile"},
									{"SkyKnight", 25, "Supersonic", 1500,"Single WAR-Head","Operational", "Short-range air defense missile system"}},
						
							   russia{{"Iskander-M (SS-26 Stone)", 500, "Hypersonic (Mach 6-7)",3066,"Single WAR-Head","Operational", "Short-range ballistic missile"},
							   		{"Topol-M (SS-27 Sickle B)", 11000, "Hypersonic (Mach 21)",3066,"Multiple WAR-Head","Operational", "Intercontinental ballistic missile (ICBM)"},
									{"Yars (SS-27 Mod 2)", 10000, "Hypersonic (Mach 20)",3066,"Multiple WAR-Head","Operational","Intercontinental ballistic missile (ICBM)"},
									{"Bulava (RSM-56)", 8000, "Hypersonic (Mach 20)",3066,"Multiple WAR-Head","Operational","Submarine-launched ballistic missile (SLBM)"},
									{"Kalibr (3M-14)", 2500, "Subsonic to Supersonic",3066,"Multiple WAR-Head","Operational", "Submarine-launched and ship-launched cruise missile"},
									{"Kinzhal (Kh-47M2)", 2000, "Hypersonic (Mach 10)",3066,"Multiple WAR-Head","Operational", "Air-launched ballistic missile"},
									{"Kinzhal (Iskander-M)", 3000, "Hypersonic (Mach 10)",3066,"Multiple WAR-Head","Operational", "Air-launched ballistic missile"}},
									
							palestine{{"Kinzhal (Iskander-M)", 3000, "Hypersonic (Mach 10)",3066,"Multiple WAR-Head","Operational", "Air-launched ballistic missile"},
								{"Qassam-I",5,"Subsonic",1000,"Single WAR-Head","Homemade","Short Range Artillery Rockets"},
								{"Qassam_II",12,"Subsonic",1000,"Single WAR-Head","Improvised","Short Range Artillery Rockets"},
								{"Yars (SS-27 Mod 2)", 10000, "Hypersonic (Mach 20)",3066,"Multiple WAR-Head","Operational","Intercontinental ballistic missile (ICBM)"},
								{"Topol-M (SS-27 Sickle B)", 11000, "Hypersonic (Mach 21)",3066,"Multiple WAR-Head","Operational", "Intercontinental ballistic missile (ICBM)"},
								{"Kalibr (3M-14)", 2500, "Subsonic to Supersonic",3066,"Multiple WAR-Head","Operational", "Submarine-launched and ship-launched cruise missile"},
								{"Bulava (RSM-56)", 8000, "Hypersonic (Mach 20)",3066,"Multiple WAR-Head","Operational","Submarine-launched ballistic missile (SLBM)"}},
								
							israel{{"Delilah",300,"subsonic",1236,"Multiple WAR-Head","Operational","Air-launched cruise missile"},
							{"Gabriel",400,"Supersonic",1000,"Multiple WAR-Head","Operational","Anti-Ship Missile"},
							{"Jericho 1",500,"Hypersonic (Mach 5)",5000,"Multiple WAR_Head","Obsolete","Short to Medium-Range Ballistic Missile (SRBM)."},
							{"Jericho 2",3500,"Hypersonic (Mach 5)",5500,"Multiple WAR-Head","Operational","Intercontinental Ballistic Missile (ICBM)"},
							{"Jericho 3",6500,"Hypersonic (Mach 5)",6000,"Multiple WAR-Head","Operational","Advanced Ballistic Missile"},
							{"Harpoon",240,"High Subsonic",900,"Multiple WAR-Head","Operational","Anti-Ship Missile"},
							{"LORA",280,"Subsonic",1000,"Multiple WAR-Head","Operational","Short-Range Ballistic Missile (SRBM)"}}
									
						
				{
				//initialization of list in constructor
				}
	
		void Attacking_missiles(double dist,string user_country[0],string specific_countries[]){

			double time=0;
		    //time= distance/missile.mach_speed;
			cout<<"The Following Missiles are Available of your Country"<<endl; 
		    
			
			if(user_country[0]==specific_countries[0]){ //  pakistan
			
				cout<<"\nYour Country Is "<<user_country[0]<<endl;
				cout<<"In This Range You Can Use These Missiles"<<endl;
		
				cout<<" ________________________________________________________________________ "<<endl;
				cout<<"|            |                                                           |"<<endl;
				cout<<"| Index No.  |\t Missile Names In Your Range"<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
		
				for(int i=0;i<11;i++){
					 
					if(pakistan[i].range>=dist){
						
						
					cout<<"|      "<<i<<"     |\t "<<pakistan[i].name<<endl;
					cout<<"|------------|-----------------------------------------------------------|"<<endl;
			
					}
						
				}
				
				cout<<"|____________|___________________________________________________________|"<<endl;
				
				
				int missile_no;
				
			
				do
				{
					cout<<"Enter the index number of missile you want to use: ";
					cin>>missile_no;
					if(missile_no>=11){
						cout<<"This Missile Is Not Available "<<endl;
						cout<<"Enter Again"<<endl;
					}else if(missile_no<=11&&pakistan[missile_no].range<dist){
						cout<<"This Missile Is Out Of Range "<<endl;
						cout<<"Enter Again"<<endl;
					}else{
						cout<<" ________________________________________________________________________ "<<endl;
						cout<<"|            |                                                           |"<<endl;
						cout<<"|  Country   |\t"<<user_country[0]<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Missile   |\t"<<pakistan[missile_no].name<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Range     |\t"<<pakistan[missile_no].range<<" KM"<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Speed     |\t"<<pakistan[missile_no].mach_speed<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  KM/h      |\t"<<pakistan[missile_no].speed<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  War-Head  |\t"<<pakistan[missile_no].warhead<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Status    |\t"<<pakistan[missile_no].status<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Type      |\t"<<pakistan[missile_no].type<<endl;
						cout<<"|____________|___________________________________________________________|"<<endl;
						time=dist/static_cast<double>(pakistan[missile_no].speed);
					}
				}while(missile_no>=11 || (missile_no<=11&&pakistan[missile_no].range<dist));
			}
			
			if(user_country[0]==specific_countries[1]){ //  saudiarabia
				
				cout<<"Your Country Is "<<user_country[0]<<endl;
				cout<<"In This Range You Can Use These Missiles"<<endl;
		
				cout<<" ________________________________________________________________________ "<<endl;
				cout<<"|            |                                                           |"<<endl;
				cout<<"| Index No.  |\t Missile Names In Your Range"<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
		
				for(int i=0;i<6;i++){
					 
					if(saudiarabia[i].range>=dist){
						
						cout<<"|      "<<i<<"     |\t "<<saudiarabia[i].name<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
		
					}
					
				}
				cout<<"|____________|___________________________________________________________|"<<endl;
				
				int missile_no;
				
				do{
					
					cout<<"Enter The Index Number Of Missile You Want To Use: ";
					cin>>missile_no;
					
					if(missile_no>=6){
						cout<<"This Missile Is Not Available "<<endl;
						cout<<"Enter Again"<<endl;
					}else if(missile_no<=6&&saudiarabia[missile_no].range<dist){
						cout<<"This Missile Is Out Of Range "<<endl;
						cout<<"Enter Again"<<endl;
					}else{
				
						cout<<" ________________________________________________________________________ "<<endl;
						cout<<"|            |                                                           |"<<endl;
						cout<<"|  Country   |\t"<<user_country[0]<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Missile   |\t"<<saudiarabia[missile_no].name<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Range     |\t"<<saudiarabia[missile_no].range<<" KM"<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Speed     |\t"<<saudiarabia[missile_no].mach_speed<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  KM/h      |\t"<<saudiarabia[missile_no].speed<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  War-Head  |\t"<<saudiarabia[missile_no].warhead<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Status    |\t"<<saudiarabia[missile_no].status<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Type      |\t"<<saudiarabia[missile_no].type<<endl;
						cout<<"|____________|___________________________________________________________|"<<endl;
						time=dist/saudiarabia[missile_no].speed;	
					}
					
				}while(missile_no>=6 || (missile_no<=6&&saudiarabia[missile_no].range<dist));
			}
			
			if(user_country[0]==specific_countries[2]){  //turkey
		
				cout<<"Your Country Is "<<user_country[0]<<endl;
				cout<<"In This Range You Can Use These Missiles"<<endl;
			
				cout<<" ________________________________________________________________________ "<<endl;
				cout<<"|            |                                                           |"<<endl;
				cout<<"| Index No.  |\t Missile Names In Your Range"<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
		
				for(int i=0;i<8;i++){
					 
				if(turkey[i].range>=dist){
						
					cout<<"|      "<<i<<"     |\t "<<turkey[i].name<<endl;
					cout<<"|------------|-----------------------------------------------------------|"<<endl;
		
					}
					
				}
				cout<<"|____________|___________________________________________________________|"<<endl;
				
				
				int missile_no;
				
				do{
					cout<<"Enter The Index Number Of Missile You Want To Use: ";
					cin>>missile_no;
					if(missile_no>=8){
						cout<<"This Missile Is Not Available "<<endl;
						cout<<"Enter Again"<<endl;
					}else if(missile_no<=8&&turkey[missile_no].range<dist){
						cout<<"This Missile Is Out Of Range "<<endl;
						cout<<"Enter Again"<<endl;
					}else{
					
						cout<<" ________________________________________________________________________ "<<endl;
						cout<<"|            |                                                           |"<<endl;
						cout<<"|  Country   |\t"<<user_country[0]<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Missile   |\t"<<turkey[missile_no].name<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Range     |\t"<<turkey[missile_no].range<<" KM"<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Speed     |\t"<<turkey[missile_no].mach_speed<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  KM/h      |\t"<<turkey[missile_no].speed<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  War-Head  |\t"<<turkey[missile_no].warhead<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Status    |\t"<<turkey[missile_no].status<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Type      |\t"<<turkey[missile_no].type<<endl;
						cout<<"|____________|___________________________________________________________|"<<endl;
						time=dist/turkey[missile_no].speed;	
					}
					
				}while(missile_no>=8 || (missile_no<=8&&turkey[missile_no].range<dist));
			}
			
			if(user_country[0]==specific_countries[3]){  //china
			
				cout<<"Your Country Is "<<user_country[0]<<endl;
				cout<<"In This Range You Can Use These Missiles"<<endl;
			
				cout<<" ________________________________________________________________________ "<<endl;
				cout<<"|            |                                                           |"<<endl;
				cout<<"| Index No.  |\t Missiles Names In Your Range"<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
			
				for(int i=0;i<13;i++){
					 
					if(china[i].range>=dist){
						
					cout<<"|      "<<i<<"     |\t "<<china[i].name<<endl;
					cout<<"|------------|-----------------------------------------------------------|"<<endl;
			
					}
					
				}
				cout<<"|____________|___________________________________________________________|"<<endl;
				
				
				int missile_no;
				
				do
				{
					cout<<"Enter The Index Number Of Missile You Want To Use: ";
					cin>>missile_no;
					if(missile_no>=13){
						cout<<"This Missile Is Not Available "<<endl;
						cout<<"Enter Again"<<endl;
					}else if(missile_no<=13&&china[missile_no].range<dist){
						cout<<"This Missile Is Out Of Range "<<endl;
						cout<<"Enter Again"<<endl;
					}else{
					
						cout<<" ________________________________________________________________________ "<<endl;
						cout<<"|            |                                                           |"<<endl;
						cout<<"|  Country   |\t"<<user_country[0]<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Missile   |\t"<<china[missile_no].name<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Range     |\t"<<china[missile_no].range<<" KM"<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Speed     |\t"<<china[missile_no].mach_speed<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  KM/h      |\t"<<china[missile_no].speed<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  War-Head  |\t"<<turkey[missile_no].warhead<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Status    |\t"<<china[missile_no].status<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Type      |\t"<<china[missile_no].type<<endl;
						cout<<"|____________|___________________________________________________________|"<<endl;
						time=dist/china[missile_no].speed;	
					}
				}while(missile_no>=13 || (missile_no<=13&&china[missile_no].range<dist));
			}
			
			
			if(user_country[0]==specific_countries[4]){  //us
			
				cout<<"Your Country Is "<<user_country[0]<<endl;
				cout<<"In This Range You Can Use These Missiles"<<endl;
			
				cout<<" ________________________________________________________________________ "<<endl;
				cout<<"|            |                                                           |"<<endl;
				cout<<"| Index No.  |\t Missiles Names In Your Range"<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
			
				for(int i=0;i<9;i++){
					 
					if(us[i].range>=dist){
						
					cout<<"|      "<<i<<"     |\t "<<us[i].name<<endl;
					cout<<"|------------|-----------------------------------------------------------|"<<endl;
			
					}
					
				}
				cout<<"|____________|___________________________________________________________|"<<endl;
				
				
				int missile_no;
				
				do{
					cout<<"Enter The Index Number Of Missile You Want To Use: ";
					cin>>missile_no;
					if(missile_no>=9){
						cout<<"This Missile Is Not Available "<<endl;
						cout<<"Enter Again"<<endl;
					}else if(missile_no<=9&&us[missile_no].range<dist){
						cout<<"This Missile Is Out Of Range "<<endl;
						cout<<"Enter Again"<<endl;
					}else{
					
						cout<<" ________________________________________________________________________ "<<endl;
						cout<<"|            |                                                           |"<<endl;
						cout<<"|  Country   |\t"<<user_country[0]<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Missile   |\t"<<us[missile_no].name<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Range     |\t"<<us[missile_no].range<<" KM"<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Speed     |\t"<<us[missile_no].mach_speed<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  KM/h      |\t"<<us[missile_no].speed<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  War-Head  |\t"<<us[missile_no].warhead<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Status    |\t"<<us[missile_no].status<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Type      |\t"<<us[missile_no].type<<endl;
						cout<<"|____________|___________________________________________________________|"<<endl;
						time=dist/us[missile_no].speed;	
					}
				}while(missile_no>=9 || (missile_no<=9&&us[missile_no].range<dist));
			}
			
		
			if(user_country[0]==specific_countries[5]){  //iran
			
				cout<<"Your Country Is "<<user_country[0]<<endl;
				cout<<"In This Range You can Use These Missiles"<<endl;
			
				cout<<" ________________________________________________________________________ "<<endl;
				cout<<"|            |                                                           |"<<endl;
				cout<<"| Index No.  |\t Missiles Names In Your Range"<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
			
				for(int i=0;i<12;i++){
					 
					if(iran[i].range>=dist){
						
						cout<<"|      "<<i<<"     |\t "<<iran[i].name<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
			
					}	
				}
				cout<<"|____________|___________________________________________________________|"<<endl;
				
				
				int missile_no;
				
				do{
					cout<<"Enter The Index Number Of Missile You Want To Use: ";
					cin>>missile_no;
					if(missile_no>=12){
						cout<<"This Missile Is Not Available "<<endl;
						cout<<"Enter Again"<<endl;
					}else if(missile_no<=12&&iran[missile_no].range<dist){
						cout<<"This Missile Is Out Of Range "<<endl;
						cout<<"Enter Again"<<endl;
					}else{
					
						cout<<" ________________________________________________________________________ "<<endl;
						cout<<"|            |                                                           |"<<endl;
						cout<<"|  Country   |\t"<<user_country[0]<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Missile   |\t"<<iran[missile_no].name<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Range     |\t"<<iran[missile_no].range<<" KM"<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Speed     |\t"<<iran[missile_no].mach_speed<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  KM/h      |\t"<<iran[missile_no].speed<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  War-Head  |\t"<<iran[missile_no].warhead<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Status    |\t"<<iran[missile_no].status<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Type      |\t"<<iran[missile_no].type<<endl;
						cout<<"|____________|___________________________________________________________|"<<endl;
						time=dist/iran[missile_no].speed;
					}
				}while(missile_no>=12 || (missile_no<=12&&iran[missile_no].range<dist));
			}
		
		
			if(user_country[0]==specific_countries[6]){  //qatar
			
				cout<<"Your Country Is "<<user_country[0]<<endl;
				cout<<"In This Range You Can Use These Missiles"<<endl;
			
				cout<<" ________________________________________________________________________ "<<endl;
				cout<<"|            |                                                           |"<<endl;
				cout<<"| Index No.  |\t Missiles Names In Your Range"<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
			
				for(int i=0;i<4;i++){
					 
					if(qatar[i].range>=dist){
								
						cout<<"|      "<<i<<"     |\t "<<qatar[i].name<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
			
					}
					
				}
				cout<<"|____________|___________________________________________________________|"<<endl;
				
				
				int missile_no;
				
				do{
					cout<<"Enter The Index Number Of Missile You Want To Use: ";
					cin>>missile_no;
					if(missile_no>=4){
						cout<<"This Missile Is Not Available "<<endl;
						cout<<"Enter Again"<<endl;
					}else if(missile_no<=4&&qatar[missile_no].range<dist){
						cout<<"This Missile Is Out Of Range "<<endl;
						cout<<"Enter Again"<<endl;
					}else{
					
						cout<<" ________________________________________________________________________ "<<endl;
						cout<<"|            |                                                           |"<<endl;
						cout<<"|  Country   |\t"<<user_country[0]<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Missile   |\t"<<qatar[missile_no].name<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Range     |\t"<<qatar[missile_no].range<<" KM"<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Speed     |\t"<<qatar[missile_no].mach_speed<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  KM/h      |\t"<<qatar[missile_no].speed<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  War-Head  |\t"<<qatar[missile_no].warhead<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Status    |\t"<<qatar[missile_no].status<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Type      |\t"<<qatar[missile_no].type<<endl;
						cout<<"|____________|___________________________________________________________|"<<endl;
						time=dist/qatar[missile_no].speed;
					}
				}while(missile_no>=4 || (missile_no<=4&&qatar[missile_no].range<dist));
			}
		
		
			if(user_country[0]==specific_countries[7]){  //india
			
				cout<<"Your Country Is "<<user_country[0]<<endl;
				cout<<"In This Range You Can Use These Missiles"<<endl;
			
				cout<<" ________________________________________________________________________ "<<endl;
				cout<<"|            |                                                           |"<<endl;
				cout<<"| Index No.  |\t Missile Names In Your Range"<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
			
				for(int i=0;i<23;i++){
					 
					if(india[i].range>=dist){
						
						cout<<"|      "<<i<<"     |\t "<<india[i].name<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
			
					}
					
				}
				cout<<"|____________|___________________________________________________________|"<<endl;
				
				
				int missile_no;
				
				do{
					cout<<"Enter The Index Number Of Missile You Want To Use: ";
					cin>>missile_no;
					if(missile_no>=23){
						cout<<"This Missile Is Not Available "<<endl;
						cout<<"Enter Again"<<endl;
					}else if(missile_no<=23&&india[missile_no].range<dist){
						cout<<"This Missile Is Out Of Range "<<endl;
						cout<<"Enter Again"<<endl;
					}else{
						cout<<" ________________________________________________________________________ "<<endl;
						cout<<"|            |                                                           |"<<endl;
						cout<<"|  Country   |\t"<<user_country[0]<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Missile   |\t"<<india[missile_no].name<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Range     |\t"<<india[missile_no].range<<" KM"<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Speed     |\t"<<india[missile_no].mach_speed<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  KM/h      |\t"<<india[missile_no].speed<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  War-Head  |\t"<<india[missile_no].warhead<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Status    |\t"<<india[missile_no].status<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Type      |\t"<<india[missile_no].type<<endl;
						cout<<"|____________|___________________________________________________________|"<<endl;
						time=dist/india[missile_no].speed;
						}
				}while(missile_no>=23 || (missile_no<=23&&india[missile_no].range<dist));
			}
		
		
			if(user_country[0]==specific_countries[8]){  //uae
			
				cout<<"Your Country is "<<user_country[0]<<endl;
				cout<<"In This Range You Can Use These Missiles"<<endl;
			
				cout<<" ________________________________________________________________________ "<<endl;
				cout<<"|            |                                                           |"<<endl;
				cout<<"| Index No.  |\t Missile Names In Your Range"<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
			
				for(int i=0;i<8;i++){
					 
					if(uae[i].range>=dist){
						
						cout<<"|      "<<i<<"     |\t "<<uae[i].name<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
			
					}
					
				}
				cout<<"|____________|___________________________________________________________|"<<endl;
				
				
				int missile_no;
				
				do{
					cout<<"Enter The Index Number Of Missile You Want To Use: ";
					cin>>missile_no;
					if(missile_no>=8){
						cout<<"This Missile Is Not Available "<<endl;
						cout<<"Enter Again"<<endl;
					}else if(missile_no<=8&&uae[missile_no].range<dist){
						cout<<"This Missile Is Out Of Range "<<endl;
						cout<<"Enter Again"<<endl;
					}else{
					
					cout<<endl;
					cout<<" ________________________________________________________________________ "<<endl;
					cout<<"|            |                                                           |"<<endl;
					cout<<"|  Country   |\t"<<user_country[0]<<endl;
					cout<<"|------------|-----------------------------------------------------------|"<<endl;
					cout<<"|  Missile   |\t"<<uae[missile_no].name<<endl;
					cout<<"|------------|-----------------------------------------------------------|"<<endl;
					cout<<"|  Range     |\t"<<uae[missile_no].range<<" KM"<<endl;
					cout<<"|------------|-----------------------------------------------------------|"<<endl;
					cout<<"|  Speed     |\t"<<uae[missile_no].mach_speed<<endl;
					cout<<"|------------|-----------------------------------------------------------|"<<endl;
					cout<<"|  KM/h      |\t"<<uae[missile_no].speed<<endl;
					cout<<"|------------|-----------------------------------------------------------|"<<endl;
					cout<<"|  War-Head  |\t"<<uae[missile_no].warhead<<endl;
					cout<<"|------------|-----------------------------------------------------------|"<<endl;
					cout<<"|  Status    |\t"<<uae[missile_no].status<<endl;
					cout<<"|------------|-----------------------------------------------------------|"<<endl;
					cout<<"|  Type      |\t"<<uae[missile_no].type<<endl;
					cout<<"|____________|___________________________________________________________|"<<endl;
					time=dist/uae[missile_no].speed;
					}
				}while(missile_no>=8 || (missile_no<=8&&uae[missile_no].range<dist));
			
			}
			
			if(user_country[0]==specific_countries[9]){  //russia
		
				cout<<"Your Country is "<<user_country[0]<<endl;
				cout<<"In this Range you can use these Missiles"<<endl;
			
				cout<<" ________________________________________________________________________ "<<endl;
				cout<<"|            |                                                           |"<<endl;
				cout<<"| Index No.  |\t Missiles Names In You Range"<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
		
				for(int i=0;i<7;i++){
					 
					if(russia[i].range>=dist){
						
						cout<<"|      "<<i<<"     |\t "<<russia[i].name<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
			
					}
					
				}
				cout<<"|____________|___________________________________________________________|"<<endl;
				
				
				int missile_no;
				
				do{
					cout<<"Enter The Index Number Of Missile You Want To Use: ";
					cin>>missile_no;
					if(missile_no>=7){
						cout<<"This Missile Is Not Available "<<endl;
						cout<<"Enter Again"<<endl;
					}else if(missile_no<=7&&russia[missile_no].range<dist){
						cout<<"This Missile Is Out Of Range "<<endl;
						cout<<"Enter Again"<<endl;
					}else{
					
						cout<<" ________________________________________________________________________ "<<endl;
						cout<<"|            |                                                           |"<<endl;
						cout<<"|  Country   |\t"<<user_country[0]<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Missile   |\t"<<russia[missile_no].name<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Range     |\t"<<russia[missile_no].range<<" KM"<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Speed     |\t"<<russia[missile_no].mach_speed<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  KM/h      |\t"<<russia[missile_no].speed<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  War-Head  |\t"<<russia[missile_no].warhead<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Status    |\t"<<russia[missile_no].status<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Type      |\t"<<russia[missile_no].type<<endl;
						cout<<"|____________|___________________________________________________________|"<<endl;
						time=dist/russia[missile_no].speed;
					}
				}while(missile_no>=7 || (missile_no<=7&&russia[missile_no].range<dist));
				
			}
			
			if(user_country[0]==specific_countries[10]){ //  palestine
			
				cout<<"Your Country Is "<<user_country[0]<<endl;
				cout<<"In This Range You Can Use These Missiles"<<endl;
		
				cout<<" ________________________________________________________________________ "<<endl;
				cout<<"|            |                                                           |"<<endl;
				cout<<"| Index No.  |\t Missiles Names In You Range"<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
		
				for(int i=0;i<11;i++){
					 
					if(palestine[i].range>=dist){
						
						cout<<"|      "<<i<<"     |\t "<<palestine[i].name<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
			
					}
						
				}
				
				cout<<"|____________|___________________________________________________________|"<<endl;
				
				
				int missile_no;
				
				do{
					cout<<"Enter The Index Number Of Missile You Want To Use: ";
					cin>>missile_no;
					if(missile_no>=11){
						cout<<"This Missile Is Not Available "<<endl;
						cout<<"Enter Again"<<endl;
						
					}else if(missile_no<=11&&palestine[missile_no].range<dist){
						cout<<"This Missile Is Out Of Range "<<endl;
						cout<<"Enter Again"<<endl;
					}else{
					
						cout<<" ________________________________________________________________________ "<<endl;
						cout<<"|            |                                                           |"<<endl;
						cout<<"|  Country   |\t"<<user_country[0]<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Missile   |\t"<<palestine[missile_no].name<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Range     |\t"<<palestine[missile_no].range<<" KM"<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Speed     |\t"<<palestine[missile_no].mach_speed<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  KM/h      |\t"<<palestine[missile_no].speed<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  War-Head  |\t"<<palestine[missile_no].warhead<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Status    |\t"<<palestine[missile_no].status<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Type      |\t"<<palestine[missile_no].type<<endl;
						cout<<"|____________|___________________________________________________________|"<<endl;
						time=dist/static_cast<double>(palestine[missile_no].speed);
					}
				}while(missile_no>=11 || (missile_no<=11&&palestine[missile_no].range<dist));
			
			}
			
			if(user_country[0]==specific_countries[11]){ //  israel
			
				cout<<"Your Country Is "<<user_country[0]<<endl;
				cout<<"In This Range You Can Use These Missiles"<<endl;
		
				cout<<" ________________________________________________________________________ "<<endl;
				cout<<"|            |                                                           |"<<endl;
				cout<<"| Index No.  |\t Missile Names In Your Range"<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
		
				for(int i=0;i<11;i++){
					 
					if(israel[i].range>=dist){
						
						cout<<"|      "<<i<<"     |\t "<<israel[i].name<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
			
					}
						
				}
				cout<<"|____________|___________________________________________________________|"<<endl;
				
				
				int missile_no;
				
				do{
					cout<<"Enter The Index Number Of Missile You Want To Use: ";
					cin>>missile_no;
					if(missile_no>=11){
						cout<<"This Missile Is Not Available "<<endl;
						cout<<"Enter Again"<<endl;
						
					}else if(missile_no<=11&&israel[missile_no].range<dist){
						cout<<"This Missile Is Out Of Range "<<endl;
						cout<<"Enter Again"<<endl;
					}else{
					
						cout<<" ________________________________________________________________________ "<<endl;
						cout<<"|            |                                                           |"<<endl;
						cout<<"|  Country   |\t"<<user_country[0]<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Missile   |\t"<<israel[missile_no].name<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Range     |\t"<<israel[missile_no].range<<" KM"<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Speed     |\t"<<israel[missile_no].mach_speed<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  KM/h      |\t"<<israel[missile_no].speed<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  War-Head  |\t"<<israel[missile_no].warhead<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Status    |\t"<<israel[missile_no].status<<endl;
						cout<<"|------------|-----------------------------------------------------------|"<<endl;
						cout<<"|  Type      |\t"<<israel[missile_no].type<<endl;
						cout<<"|____________|___________________________________________________________|"<<endl;
						time=dist/static_cast<double>(israel[missile_no].speed);
					}
				}while(missile_no>=11 || (missile_no<=11&&israel[missile_no].range<dist));
			}
			
			
			cout<<"\nTime To Hit The Target \n";
				cout<<" ______________________________________________________"<<endl;
				cout<<"|                         |                            |"<<endl;
				cout<<"|    Time(sec)            |\t"<<time*60<<" MIN "<<endl;
				cout<<"|_________________________|____________________________|\n"<<endl;
		}
};

void case1::distanceCalculate(){
	double formula_for_distance(double latitude_1,double longitude_1,double latitude_2,double longitude_2);
	int distance=formula_for_distance(user_city_latitude,user_city_longitude,enemy_city_latitude,enemy_city_longitude);
	cout<<" ______________________________________________________"<<endl;
	cout<<"|                         |                            |"<<endl;
	cout<<"|    Distance is :        |\t"<<distance<<" KM "<<endl;  
	cout<<"|_________________________|____________________________|\n"<<endl;
	attackingMissile obj;
	obj.Attacking_missiles(distance,user_country,user_specificcountries);
}
		 
		 
		 
double formula_for_distance(double latitude_1,double longitude_1,double latitude_2,double longitude_2){
	latitude_1=latitude_1*(3.14/180);
	longitude_1=longitude_1*(3.14/180);
	latitude_2=latitude_2*(3.14/180);
	longitude_2=longitude_2*(3.14/180);
	
	double diff_latitude=latitude_2-latitude_1;
	double diff_longitude=longitude_2-longitude_1;
	double a=sin(diff_latitude/2)*sin(diff_latitude/2)+cos(latitude_1)*cos(latitude_2)*sin(diff_longitude/2)*sin(diff_longitude/2);
	double c=2*atan2(sqrt(a),sqrt(1-a));
	double radius_earth=6371;
	double distance;
	distance=c*radius_earth;
	return distance;
}

			////////////////////////////////// FILE HANDLING  /////////////////////////////////
class case2 {
public:
	
	void save_data(int n,Missile data[]){
	
			ofstream file;
			file.open("missile_data.txt",ios::app);
			
			for(int i=0;i<n;i++){
	
			file<<" ________________________________________________________________________ "<<endl;
			file<<"|            |                                                           |"<<endl;
			file<<"|------------|-----------------------------------------------------------|"<<endl;
			file<<"|  Missile   |\t"<<data[i].name<<endl;
			file<<"|------------|-----------------------------------------------------------|"<<endl;
			file<<"|  Range     |\t"<<data[i].range<<endl;
			file<<"|------------|-----------------------------------------------------------|"<<endl;
			file<<"|  Speed     |\t"<<data[i].speed<<endl;
			file<<"|------------|-----------------------------------------------------------|"<<endl;
			file<<"|____________|___________________________________________________________|"<<endl;
			
			}
			
			file.close();
		
	}
	
	void read_user_data(){	
	int n;
    cout<<"How Many Missiles's Data You Will Store ?"<<endl;
    cin>>n;
    cin.ignore();

    Missile *data=new Missile[n];
    
	for(int i=0;i<n;i++){
//		cin.ignore();
        cout<<"Missiles Name:";
        getline(cin,data[i].name);
        cout<<"Missiles Range:";
        cin>>data[i].range;
        cout<<"Missiles Speed:";
        cin>>data[i].speed;
        cin.ignore();
    }
    int save;
    cout<<"Press 1 To Save Data OR 0 To Quit"<<endl;
    cin>>save;
    if(save==1){
//	cout<<"------------"<<endl;
    	save_data(n,data);
	}
		delete[] data;
	}

	void read_file_data(){
		
		ifstream file;
		
		file.open("missile_data.txt");
		
		string data;
		
		while(getline(file,data)){
			cout<<data<<endl;
		}
		
	//	file>>data;
		
		file.close();
	//	cout<<data; 
	}
	void filehandling(){
		int option;
		case2 *c1 = new case2();
		while(true){
			cout<<"1. Write Data"<<endl;
			cout<<"2. Retrive Data"<<endl;
			cout<<"3. Exit"<<endl;
			cin>>option;
			if(option==1){
				c1->read_user_data();
			}
			else if(option==2){
				c1->read_file_data();
			}
			else{
				break;
			}
		}
	}
};
			
			/////////////////////////////////////////////////////////////////////////////////////////////
			
			
			
			////////////////////////////////// Analyse Defence System  /////////////////////////////////
class case3{
	
	private:
		string specific_countries[12]={"pakistan","saudiarabia","turkey","china","us","iran","qatar","india","uae","russia","palestine","israel"};
		Missile pakistan[9];
		Missile saudiarabia[6];
		Missile turkey[8];
		Missile china[13];
		Missile us[9];
		Missile iran[12];
		Missile qatar[4];
		Missile india[23];
		Missile uae[5];
		Missile russia[7];
		Missile palestine[7];
		Missile israel[7];
		string user_country[1];	
		bool verify_user_country=false;				
		int missile_no;
		
	
	public:
		case3():		pakistan 	{{"Babur-3",450,"Mach 2.0",2470,"Single WAR-Head","Operational","Cruise missile"},
									{"Ghaznavi",290,"Mach 5",6174,"Single WAR-Head","Operational","Short Range Ballistic missile"},
									{"Shaheen I",750,"Mach 5",6174,"Single WAR-Head","Operational","Short Range Ballistic missile"},
									{"Shaheen II",1500,"Mach 5",6174,"Multiple WAR-Head","Operational","Mid Range Ballistic missile"},
									{"Ababeel",2200,"Mach 5",6174,"Multiple WAR-Head","Operational","Intermediate Range Ballistic missile"},
									{"Nasr",70,"Mach 5",6174,"Single WAR-Head","Operational","Short Range Ballistic missile"},
									{"Ra'ad (Hatf VIII)",700,"Mach 0.7",990,"Single WAR-Head","Operational","Air Launched-Cruise Missile"},
									{"Babur (Hatf VII)",700,"Mach 0.7",990,"Single WAR-Head","Operational","Ground Launched-Cruise Missile"},
									{"Shaheen III",700,"Mach 0.7",990,"Single WAR-Head","Operational","ballistic"}},
									
						saudiarabia {{"DF-3 (Al-Samoud)", 2600, "Mach 5", 132,"Multiple WAR-Head", "Intermediate-range ballistic missile"},
									{"DF-21 (Al-Watah)", 1500, "Mach 5", 4231,"Multiple WAR-Head", "Medium-range ballistic missile"},
    								{"DF-61 (Al-Hussein)", 600, "Mach 5", 4121,"Single WAR-Head", "Short-range ballistic missile"},
									{"Patriot Missile System", 150, "Mach 5", 431,"Single WAR-Head", "Surface-to-air missile system"},
									{"Al-Sadiq (Skyguard)", 3, "Supersonic",2411,"Single WAR-Head", "Short-range air defense system"},
									{"CSS-2 (Dong Feng-3)", 2800, "Supersonic", 453, "Multiple WAR-Head","Intermediate-range ballistic missile"}},
									
						turkey		{{"Bora (KAAN)", 280, "Supersonic", 345,"Single WAR-Head", "Tactical ballistic missile"},
							  		{"Atmaca", 220, "Subsonic", 2600,"Single WAR-Head", "Anti-ship cruise missile"},
									{"SOM (Standoff Missile)", 250, "Subsonic", 534,"Single WAR-Head","Operational", "Air-launched cruise missile"},
									{"Hisar-A", 0, "Supersonic", 0,"Single WAR-Head","Operational", "Short-range air defense missile system"},
									{"Hisar-O", 0, "Supersonic", 0, "Multiple WAR-Head","Operational","Medium-range air defense missile system"},
									{"Roketsan T-122 Sakarya", 300, "Supersonic", 2321, "Single WAR-Head","Operational","Tactical ballistic missile"},
									{"J600T Yildirim", 280, "Supersonic", 3421, "Single WAR-Head","Operational","Tactical ballistic missile"},
									{"BMC Tacir", 200, "Hypersonic",2342, "Single WAR-Head","Operational", "Precision-guided stand-off missile"}},
									
						china		{{"DF-41 (Dongfeng-41)", 12000, "Hypersonic", 2600, "Multiple WAR-Head", "Intercontinental Ballistic Missile (ICBM)"},
							   		{"DF-31 (Dongfeng-31)", 11200, "Hypersonic",3453, "Multiple WAR-Head", "Intercontinental Ballistic Missile (ICBM)"},
									{"DF-26 (Dongfeng-26)", 3000, "Hypersonic", 4000, "Multiple WAR-Head", "Intermediate-range Ballistic Missile (IRBM)"},
									{"DF-21D (Dongfeng-21D)", 1500, "Hypersonic", 1700, "Multiple WAR-Head","Operational","Anti-ship Ballistic Missile (ASBM)"},
									{"DF-17 (Dongfeng-17)", 1500, "Hypersonic", 2000, "Multiple WAR-Head","Operational","Hypersonic Glide Vehicle (HGV)"},
    								{"DF-16 (Dongfeng-16)", 800, "Hypersonic", 1000, "Single WAR-Head", "Short-range Ballistic Missile (SRBM)"},
									{"DF-15 (Dongfeng-15)", 600, "Hypersonic", 900, "Single WAR-Head", "Short-range Ballistic Missile (SRBM)"},
									{"CJ-10 (Changjian-10)", 1500, "Subsonic", 3453, "Multiple WAR-Head", "Land-attack cruise missile"},
									{"YJ-18", 500, "Supersonic",321, "Single WAR-Head", "Anti-ship cruise missile"},
   									{"HQ-9", 200, "Hypersonic",3453,  "Single WAR-Head","Long-range surface-to-air missile system"},
									{"DH-10 (HongNiao)", 1500, "Subsonic", 2500, "Multiple WAR-Head", "Land-attack cruise missile"},
									{"CJ-20 (Changjian-20)", 1500, "Subsonic", 2500, "Multiple WAR-Head", "Land-attack cruise missile"}},
									
						us			{{"AIM-120(AMRAAM)", 180, "Mach 4",3066,"Single WAR-Head","Operational","Air-to-Air Missile"},
									{"AGM-114 Hellfire", 8, "Subsonic",3066,"Single WAR-Head","Operational","Air-to-ground missile"},
								  	{"Tomahawk", 1600, "Subsonic",3066, "Multiple WAR-Head","Operational", "Land-attack cruise missile"},
				   				  	{"Minuteman III", 13000, "Hypersonic (reentry speed)",3066, "Multiple WAR-Head","Operational","Intercontinental Ballistic Missile (ICBM)"},
								  	{"BGM-71 TOW", 4.5, "Subsonic",3066,"Single WAR-Head","Operational","Anti-tank guided missile"},
								  	{"Patriot Missile System (MIM-104)", 160, "Hypersonic",3066,"Single WAR-Head","Operational", "Surface-to-air missile system"},
				    			  	{"Standard Missile (SM-2, SM-3, SM-6)", 0, "Varies by variant",3066,"Single WAR-Head","Operational","Naval surface-to-air and anti-ballistic missile"},
								  	{"AGM-158 Joint Air-to-Surface Standoff Missile (JASSM)", 370, "Subsonic",3066,"Single WAR-Head","Operational","Air-launched cruise missile"},
								  	{"RIM-174 S Missile (ERAM)", 500, "Hypersonic",3066,"Single WAR-Head","Operational", "Extended range surface-to-air missile"}},
								  
						iran		{{"Soumar", 700, "Subsonic",2470,"Single WAR-Head","operational", "Cruise missile"},
								  	{"Khorramshahr", 2000, "subsonic",3066,"Multiple WAR-Head","operational", "Medium-range ballistic missile"},
									{"Emad", 1700, "subsonic",3066,"operational","Multiple WAR-Head","Medium-range ballistic missile"},
									{"Zolfaghar", 700, "subsonic",3066,"Single WAR-Head","operational", "Short-range ballistic missile"},
									{"Fateh-110 (Naze'at)", 300, "Supersonic",3066,"Single WAR-Head","operational", "Short-range ballistic missile"},
									{"Qiam", 800, "supersonic",3066,"Single WAR-Head","operational", "Short-range ballistic missile"},
									{"Sejjil-1", 2000, "subsonic",3066,"Multiple WAR-Head","operational", "Ballistic missiles"},
									{"Sejjil-2", 2000, "subsonic",3066,"Multiple WAR-Head","operational", "Ballistic missiles"},
									{"Shahab-1", 1000, "subsoni",3066,"Multiple WAR-Head","operational", "Ballistic missiles"},
									{"Shahab-2", 1500, "Supersonic",3066,"Multiple WAR-Head","operational", "Ballistic missiles"},
									{"Shahab-3", 2000, "Supersonic",3066,"Multiple WAR-Head","operational", "Ballistic missiles"}},
								
						qatar		{{"NASAMS ", 10000, "Varies",3066,"Multiple WAR-Head","Operational", "Surface-to-air missile system"},
									{"Patriot Missile System (MIM-104)", 0, "Varies",3066,"Single WAR-Head","Operational", "Surface-to-air missile system"},
									{"Javelin", 4, "Supersonic",3066,"Single WAR-Head","Operational","Man-portable, fire-and-forget infrared-guided missile"},
									{"Harpoon", 120, "Subsonic",3066,"Single WAR-Head", "operational", "Anti-ship missile"}},
									  
						india		{{"Prithvi I", 600, "Subsonic",700,"Single WAR-Head","Operational", "Tactical surface-to-surface ballistic missile"},
									{"Prithvi II", 600, "Subsonic",2000,"Single WAR-Head","Operational", "Tactical surface-to-surface ballistic missile"},
									{"Prithvi III", 600, "Subsonic",2000,"Single WAR-Head","Operational", "Tactical surface-to-surface ballistic missile"},
									{"Agni-I", 5000, "Subsonic",3066,"Multiple WAR-Head","operational","Intermediate-range ballistic missile (IRBM)"},
									{"Agni-II", 5000, "Subsonic",200,"Multiple WAR-Head","operational", "Intercontinental ballistic missile (ICBM)"},
									{"Agni-III", 5000, "Subsonic",600,"Multiple WAR-Head","operational","Intermediate-range ballistic missile (IRBM)"},
									{"Agni-IV", 5000, "Subsonic",3066,"Multiple WAR-Head","Operational","Intercontinental ballistic missile (ICBM)"},
									{"Agni-V", 5000, "Subsonic",3066,"Multiple WAR-Head","Operational","Intermediate-range ballistic missile (IRBM)"},
									{"Agni-VI", 5000, "Subsonic",3066,"Multiple WAR-Head","Operational","Intercontinental ballistic missile (ICBM)"},
									{"Akash Mk1", 25, "Supersonic",700,"Single WAR-Head","Operational", "Medium-range surface-to-air missile"},
									{"Akash Mk2", 25, "Supersonic",3066,"Single WAR-Head","Operational","Medium-range surface-to-air missile"},
									{"BrahMos Land-launched", 500, "Supersonic",2000,"Single WAR-Head","Operational", "Supersonic cruise missile"},
									{"BrahMos Ship-launched", 500, "Supersonic",3066,"Single WAR-Head","operational","Supersonic cruise missile"},
									{"BrahMos Air-launched", 500, "Supersonic",3066,"Single WAR-Head","Operational","Supersonic cruise missile"},
									{"Dhanush", 350, "Subsonic",3066,"Single WAR-Head","Operational","Ship-launched ballistic missile"},
									{"Prahaar", 150, "Supersonic",3066,"Single WAR-Head","Operational","Tactical surface-to-surface ballistic missile"},
									{"Nirbhay", 1000, "Subsonic",3066,"Multiple WAR-Head","operational","Long-range subsonic cruise missile"}},
						
						uae			{{"Al Mursad", 300, "Mach 3", 1800,"Single WAR-Head","Operational", "Surface-to-air missile system"},
								  	{"Yabhon United 40", 500, "Subsonic", 800,"Single WAR-Head","Operational", "Cruise missile"},
					    			{"Al Tariq", 1000, "Mach 4", 2500,"Single WAR-Head","Under Development", "Ballistic missile"},
									{"Qasem", 120, "Supersonic", 1600,"Single WAR-Head","Operational", "Anti-ship cruise missile"},
									{"SkyKnight", 25, "Supersonic", 1500,"Single WAR-Head","Operational", "Short-range air defense missile system"}},
						
						russia		{{"Iskander-M (SS-26 Stone)", 500, "Hypersonic (Mach 6-7)",3066,"Single WAR-Head","Operational", "Short-range ballistic missile"},
							   		{"Topol-M (SS-27 Sickle B)", 11000, "Hypersonic (Mach 21)",3066,"Multiple WAR-Head","Operational", "Intercontinental ballistic missile (ICBM)"},
									{"Yars (SS-27 Mod 2)", 10000, "Hypersonic (Mach 20)",3066,"Multiple WAR-Head","Operational","Intercontinental ballistic missile (ICBM)"},
									{"Bulava (RSM-56)", 8000, "Hypersonic (Mach 20)",3066,"Multiple WAR-Head","Operational","Submarine-launched ballistic missile (SLBM)"},
									{"Kalibr (3M-14)", 2500, "Subsonic to Supersonic",3066,"Multiple WAR-Head","Operational", "Submarine-launched and ship-launched cruise missile"},
									{"Kinzhal (Kh-47M2)", 2000, "Hypersonic (Mach 10)",3066,"Multiple WAR-Head","Operational", "Air-launched ballistic missile"},
									{"Kinzhal (Iskander-M)", 3000, "Hypersonic (Mach 10)",3066,"Multiple WAR-Head","Operational", "Air-launched ballistic missile"}},
									
						palestine	{{"Kinzhal (Iskander-M)", 3000, "Hypersonic (Mach 10)",3066,"Multiple WAR-Head","Operational", "Air-launched ballistic missile"},
									{"Qassam-I",5,"Subsonic",1000,"Single WAR-Head","Homemade","Short Range Artillery Rockets"},
									{"Qassam_II",12,"Subsonic",1000,"Single WAR-Head","Improvised","Short Range Artillery Rockets"},
									{"Yars (SS-27 Mod 2)", 10000, "Hypersonic (Mach 20)",3066,"Multiple WAR-Head","Operational","Intercontinental ballistic missile (ICBM)"},
									{"Topol-M (SS-27 Sickle B)", 11000, "Hypersonic (Mach 21)",3066,"Multiple WAR-Head","Operational", "Intercontinental ballistic missile (ICBM)"},
									{"Kalibr (3M-14)", 2500, "Subsonic to Supersonic",3066,"Multiple WAR-Head","Operational", "Submarine-launched and ship-launched cruise missile"},
									{"Bulava (RSM-56)", 8000, "Hypersonic (Mach 20)",3066,"Multiple WAR-Head","Operational","Submarine-launched ballistic missile (SLBM)"}},
								
						israel		{{"Delilah",300,"subsonic",1236,"Multiple WAR-Head","Operational","Air-launched cruise missile"},
									{"Gabriel",400,"Supersonic",1000,"Multiple WAR-Head","Operational","Anti-Ship Missile"},
									{"Jericho 1",500,"Hypersonic (Mach 5)",5000,"Multiple WAR_Head","Obsolete","Short to Medium-Range Ballistic Missile (SRBM)."},
									{"Jericho 2",3500,"Hypersonic (Mach 5)",5500,"Multiple WAR-Head","Operational","Intercontinental Ballistic Missile (ICBM)"},
									{"Jericho 3",6500,"Hypersonic (Mach 5)",6000,"Multiple WAR-Head","Operational","Advanced Ballistic Missile"},
									{"Harpoon",240,"High Subsonic",900,"Multiple WAR-Head","Operational","Anti-Ship Missile"},
									{"LORA",280,"Subsonic",1000,"Multiple WAR-Head","Operational","Short-Range Ballistic Missile (SRBM)"}}
									
						
				{
				//initialization of list in constructor
				}
				
				void displaydata();
};


void case3::displaydata(){
	cout<<"Enter The Name Of The Country You Want To Analyse (Defence System):"<<endl;
	cin>>user_country[0];
				    
	while (verify_user_country==false){
		for(int i=0 ; i<12 ;i++){
			if(user_country[0] == specific_countries[i]){
				verify_user_country=true;
				cout<<"Data Of This Country Is Available In Our Database\n";
				break;
			}
		}
				
		if(verify_user_country==false){
			cout<<"You Entered an Invalid Country Name OR The Data Of This Country Is Not Available In Our Database"<<endl;
			cout<<"\aEnter a Right Country Name : "<<endl;
			cin>>user_country[0];
		}
	}	
	cout<<"The Following Missiles Are Available Of Your Country"<<endl; 
				
	if(user_country[0]==specific_countries[0]){ //  pakistan
						
		cout<<"\nYour Country Is "<<user_country[0]<<endl;
					
		cout<<" ________________________________________________________________________ "<<endl;
		cout<<"|            |                                                           |"<<endl;
		cout<<"| Index No.  |\t Missiles Names "<<endl;
		cout<<"|------------|-----------------------------------------------------------|"<<endl;
				
		for(int i=0;i<11;i++){
								
			cout<<"|      "<<i<<"     |\t "<<pakistan[i].name<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
							
		}
		cout<<"|____________|___________________________________________________________|"<<endl;
					
		do{
			cout<<"Enter The Index number Of Missile You Want To See More Details About: ";
			cin>>missile_no;
			if(missile_no>=11){
				cout<<"This Missile Is Not Available "<<endl;
				cout<<"Enter Again"<<endl;
			}else{
						
			cout<<" ________________________________________________________________________ "<<endl;
			cout<<"|            |                                                           |"<<endl;
			cout<<"|  Country   |\t"<<user_country[0]<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
			cout<<"|  Missile   |\t"<<pakistan[missile_no].name<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
			cout<<"|  Range     |\t"<<pakistan[missile_no].range<<" KM"<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
			cout<<"|  Speed     |\t"<<pakistan[missile_no].mach_speed<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
			cout<<"|  KM/h      |\t"<<pakistan[missile_no].speed<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
			cout<<"|  Status    |\t"<<pakistan[missile_no].status<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
			cout<<"|  Type      |\t"<<pakistan[missile_no].type<<endl;
			cout<<"|____________|___________________________________________________________|"<<endl;
			}
		}while(missile_no>=11);
	}
	
	if(user_country[0]==specific_countries[1]){ //  saudiarabia
		
		cout<<"\nYour Country Is "<<user_country[0]<<endl;

		cout<<" ________________________________________________________________________ "<<endl;
		cout<<"|            |                                                           |"<<endl;
		cout<<"| Index No.  |\t Missile Names In Your Range"<<endl;
		cout<<"|------------|-----------------------------------------------------------|"<<endl;

		for(int i=0;i<6;i++){
				
			cout<<"|      "<<i<<"     |\t "<<saudiarabia[i].name<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
		
		}
		cout<<"|____________|___________________________________________________________|"<<endl;
				
		do{
			cout<<"Enter The Index number Of Missile You Want To See More Details About: ";
			cin>>missile_no;
			if(missile_no>=6){
				cout<<"This Missile Is Not Available "<<endl;
				cout<<"Enter Again"<<endl;
			}else{
		
				cout<<" ________________________________________________________________________ "<<endl;
				cout<<"|            |                                                           |"<<endl;
				cout<<"|  Country   |\t"<<user_country[0]<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  Missile   |\t"<<saudiarabia[missile_no].name<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  Range     |\t"<<saudiarabia[missile_no].range<<" KM"<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  Speed     |\t"<<saudiarabia[missile_no].mach_speed<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  KM/h      |\t"<<saudiarabia[missile_no].speed<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  Status    |\t"<<saudiarabia[missile_no].status<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  Type      |\t"<<saudiarabia[missile_no].type<<endl;
				cout<<"|____________|___________________________________________________________|"<<endl;
			}
		}while(missile_no>=6);	
	}
	
	if(user_country[0]==specific_countries[2]){  //turkey
		
		cout<<"\nYour Country Is "<<user_country[0]<<endl;
		cout<<" ________________________________________________________________________ "<<endl;
		cout<<"|            |                                                           |"<<endl;
		cout<<"| Index No.  |\t Missile Names In Your Range"<<endl;
		cout<<"|------------|-----------------------------------------------------------|"<<endl;

		for(int i=0;i<8;i++){

				
			cout<<"|      "<<i<<"     |\t "<<turkey[i].name<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;

			
		}
		cout<<"|____________|___________________________________________________________|"<<endl;

		do{
			cout<<"Enter The Index number Of Missile You Want To See More Details About: ";
			cin>>missile_no;
			if(missile_no>=8){
				cout<<"This Missile Is Not Available "<<endl;
				cout<<"Enter Again"<<endl;
			}
		else{
		
			cout<<" ________________________________________________________________________ "<<endl;
			cout<<"|            |                                                           |"<<endl;
			cout<<"|  Country   |\t"<<user_country[0]<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
			cout<<"|  Missile   |\t"<<turkey[missile_no].name<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
			cout<<"|  Range     |\t"<<turkey[missile_no].range<<" KM"<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
			cout<<"|  Speed     |\t"<<turkey[missile_no].mach_speed<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
			cout<<"|  KM/h      |\t"<<turkey[missile_no].speed<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
			cout<<"|  Status    |\t"<<turkey[missile_no].status<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
			cout<<"|  Type      |\t"<<turkey[missile_no].type<<endl;
			cout<<"|____________|___________________________________________________________|"<<endl;
			}
		}while(missile_no>=8);
	
	}
	
	if(user_country[0]==specific_countries[3]){  //china
	
		cout<<"\nYour Country Is "<<user_country[0]<<endl;
		cout<<" ________________________________________________________________________ "<<endl;
		cout<<"|            |                                                           |"<<endl;
		cout<<"| Index No.  |\t Missiles Name In Your Range"<<endl;
		cout<<"|------------|-----------------------------------------------------------|"<<endl;
	
		for(int i=0;i<13;i++){
				
			cout<<"|      "<<i<<"     |\t "<<china[i].name<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
			
		}
		cout<<"|____________|___________________________________________________________|"<<endl;
		
		do{
			cout<<"Enter The Index number Of Missile You Want To See More Details About: ";
			cin>>missile_no;
			if(missile_no>=13){
				cout<<"This Missile Is Not Available "<<endl;
				cout<<"Enter Again"<<endl;
				
			}else{
			
				cout<<" ________________________________________________________________________ "<<endl;
				cout<<"|            |                                                           |"<<endl;
				cout<<"|  Country   |\t"<<user_country[0]<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  Missile   |\t"<<china[missile_no].name<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  Range     |\t"<<china[missile_no].range<<" KM"<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  Speed     |\t"<<china[missile_no].mach_speed<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  KM/h      |\t"<<china[missile_no].speed<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  Status    |\t"<<china[missile_no].status<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  Type      |\t"<<china[missile_no].type<<endl;
				cout<<"|____________|___________________________________________________________|"<<endl;
			}
		}while(missile_no>=13);
	}

	if(user_country[0]==specific_countries[4]){  //us
	
		cout<<"\nYour Country Is "<<user_country[0]<<endl;

		cout<<" ________________________________________________________________________ "<<endl;
		cout<<"|            |                                                           |"<<endl;
		cout<<"| Index No.  |\t Missiles Names "<<endl;
		cout<<"|------------|-----------------------------------------------------------|"<<endl;
	
		for(int i=0;i<9;i++){
	
			cout<<"|      "<<i<<"     |\t "<<us[i].name<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;

		}
		cout<<"|____________|___________________________________________________________|"<<endl;

		do{
			cout<<"Enter The Index number Of Missile You Want To See More Details About: ";
			cin>>missile_no;
			if(missile_no>=9){
				cout<<"This Missile Is Not Available "<<endl;
				cout<<"Enter Again"<<endl;
			}else{
		
			cout<<" ________________________________________________________________________ "<<endl;
			cout<<"|            |                                                           |"<<endl;
			cout<<"|  Country   |\t"<<user_country[0]<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
			cout<<"|  Missile   |\t"<<us[missile_no].name<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
			cout<<"|  Range     |\t"<<us[missile_no].range<<" KM"<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
			cout<<"|  Speed     |\t"<<us[missile_no].mach_speed<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
			cout<<"|  KM/h      |\t"<<us[missile_no].speed<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
			cout<<"|  Status    |\t"<<us[missile_no].status<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
			cout<<"|  Type      |\t"<<us[missile_no].type<<endl;
			cout<<"|____________|___________________________________________________________|"<<endl;
			}
		}while(missile_no>=9);
	
	}

	if(user_country[0]==specific_countries[5]){  //iran
	
		cout<<"\nYour Country Is "<<user_country[0]<<endl;
	
		cout<<" ________________________________________________________________________ "<<endl;
		cout<<"|            |                                                           |"<<endl;
		cout<<"| Index No.  |\t Missile Names In Your Range"<<endl;
		cout<<"|------------|-----------------------------------------------------------|"<<endl;
	
		for(int i=0;i<12;i++){
				
			cout<<"|      "<<i<<"     |\t "<<iran[i].name<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
			
		}
		cout<<"|____________|___________________________________________________________|"<<endl;
		
		do{
			cout<<"Enter The Index number Of Missile You Want To See More Details About: ";
			cin>>missile_no;
			if(missile_no>=12){
				cout<<"This Missile Is Not Available "<<endl;
				cout<<"Enter Again"<<endl;
			}else{
		
			cout<<" ________________________________________________________________________ "<<endl;
			cout<<"|            |                                                           |"<<endl;
			cout<<"|  Country   |\t"<<user_country[0]<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
			cout<<"|  Missile   |\t"<<iran[missile_no].name<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
			cout<<"|  Range     |\t"<<iran[missile_no].range<<" KM"<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
			cout<<"|  Speed     |\t"<<iran[missile_no].mach_speed<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
			cout<<"|  KM/h      |\t"<<iran[missile_no].speed<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
			cout<<"|  Status    |\t"<<iran[missile_no].status<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
			cout<<"|  Type      |\t"<<iran[missile_no].type<<endl;
			cout<<"|____________|___________________________________________________________|"<<endl;
			}
		}while(missile_no>=12);
	}


	if(user_country[0]==specific_countries[6]){  //qatar
	
		cout<<"\nYour Country Is "<<user_country[0]<<endl;

		cout<<" ________________________________________________________________________ "<<endl;
		cout<<"|            |                                                           |"<<endl;
		cout<<"| Index No.  |\t Missile Names In Your Range"<<endl;
		cout<<"|------------|-----------------------------------------------------------|"<<endl;
	
		for(int i=0;i<4;i++){
	
			cout<<"|      "<<i<<"     |\t "<<qatar[i].name<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
			
		}
		cout<<"|____________|___________________________________________________________|"<<endl;

		do{
			cout<<"Enter The Index number Of Missile You Want To See More Details About: ";
			cin>>missile_no;
			if(missile_no>=4){
				cout<<"This Missile Is Not Available "<<endl;
				cout<<"Enter Again"<<endl;
			}else{
		
			cout<<" ________________________________________________________________________ "<<endl;
			cout<<"|            |                                                           |"<<endl;
			cout<<"|  Country   |\t"<<user_country[0]<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
			cout<<"|  Missile   |\t"<<qatar[missile_no].name<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
			cout<<"|  Range     |\t"<<qatar[missile_no].range<<" KM"<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
			cout<<"|  Speed     |\t"<<qatar[missile_no].mach_speed<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
			cout<<"|  KM/h      |\t"<<qatar[missile_no].speed<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
			cout<<"|  Status    |\t"<<qatar[missile_no].status<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
			cout<<"|  Type      |\t"<<qatar[missile_no].type<<endl;
			cout<<"|____________|___________________________________________________________|"<<endl;
			}
		}while(missile_no>=4);

	}


	if(user_country[0]==specific_countries[7]){  //india
	
		cout<<"\nYour Country Is "<<user_country[0]<<endl;

		cout<<" ________________________________________________________________________ "<<endl;
		cout<<"|            |                                                           |"<<endl;
		cout<<"| Index No.  |\t Missile Names In Your Range"<<endl;
		cout<<"|------------|-----------------------------------------------------------|"<<endl;
	
		for(int i=0;i<17;i++){
				
			cout<<"|      "<<i<<"     |\t "<<india[i].name<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
	
		}
		cout<<"|____________|___________________________________________________________|"<<endl;
		
		do{
			cout<<"Enter The Index number Of Missile You Want To See More Details About: ";
			cin>>missile_no;
			if(missile_no>=17){
				cout<<"This Missile Is Not Available "<<endl;
				cout<<"Enter Again"<<endl;
			}else{
			
				cout<<" ________________________________________________________________________ "<<endl;
				cout<<"|            |                                                           |"<<endl;
				cout<<"|  Country   |\t"<<user_country[0]<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  Missile   |\t"<<india[missile_no].name<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  Range     |\t"<<india[missile_no].range<<" KM"<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  Speed     |\t"<<india[missile_no].mach_speed<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  KM/h      |\t"<<india[missile_no].speed<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  Status    |\t"<<india[missile_no].status<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  Type      |\t"<<india[missile_no].type<<endl;
				cout<<"|____________|___________________________________________________________|"<<endl;
			}
		}while(missile_no>=17);
	}
	


	if(user_country[0]==specific_countries[8]){  //uae
	
		cout<<"\nYour Country Is "<<user_country[0]<<endl;
		cout<<"In This Range You Can Use These Missiles"<<endl;
	
		cout<<" ________________________________________________________________________ "<<endl;
		cout<<"|            |                                                           |"<<endl;
		cout<<"| Index No.  |\t Missile Names In Your Range"<<endl;
		cout<<"|------------|-----------------------------------------------------------|"<<endl;
	
		for(int i=0;i<8;i++){

				
			cout<<"|      "<<i<<"     |\t "<<uae[i].name<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
	
		}
		cout<<"|____________|___________________________________________________________|"<<endl;

		do{
			cout<<"Enter The Index number Of Missile You Want To See More Details About: ";
			cin>>missile_no;
			if(missile_no>=8){
				cout<<"This Missile Is Not Available "<<endl;
				cout<<"Enter Again"<<endl;
			}else{
		
				cout<<endl;
				cout<<" ________________________________________________________________________ "<<endl;
				cout<<"|            |                                                           |"<<endl;
				cout<<"|  Country   |\t"<<user_country[0]<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  Missile   |\t"<<uae[missile_no].name<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  Range     |\t"<<uae[missile_no].range<<" KM"<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  Speed     |\t"<<uae[missile_no].mach_speed<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  KM/h      |\t"<<uae[missile_no].speed<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  Status    |\t"<<uae[missile_no].status<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  Type      |\t"<<uae[missile_no].type<<endl;
				cout<<"|____________|___________________________________________________________|"<<endl;
			}
		}while(missile_no>=8);

	}
	
	if(user_country[0]==specific_countries[9]){  //russia
	
		cout<<"\nYour Country Is "<<user_country[0]<<endl;
	
		cout<<" ________________________________________________________________________ "<<endl;
		cout<<"|            |                                                           |"<<endl;
		cout<<"| Index No.  |\t Missile Names In Your Range"<<endl;
		cout<<"|------------|-----------------------------------------------------------|"<<endl;
	
		for(int i=0;i<7;i++){
				
			cout<<"|      "<<i<<"     |\t "<<russia[i].name<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
			
		}
		cout<<"|____________|___________________________________________________________|"<<endl;

		do{
			cout<<"Enter The Index Number Of Missile You Want To Use: ";
			cin>>missile_no;
			if(missile_no>=7){
				cout<<"This Missile Is Not Available "<<endl;
				cout<<"Enter Again"<<endl;
			}else{
		
				cout<<" ________________________________________________________________________ "<<endl;
				cout<<"|            |                                                           |"<<endl;
				cout<<"|  Country   |\t"<<user_country[0]<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  Missile   |\t"<<russia[missile_no].name<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  Range     |\t"<<russia[missile_no].range<<" KM"<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  Speed     |\t"<<russia[missile_no].mach_speed<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  KM/h      |\t"<<russia[missile_no].speed<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  Status    |\t"<<russia[missile_no].status<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  Type      |\t"<<russia[missile_no].type<<endl;
				cout<<"|____________|___________________________________________________________|"<<endl;
			}
		}while(missile_no>=7);

	}
	
	
	
	if(user_country[0]==specific_countries[10]){  //palestine
	
		cout<<"\nYour Country Is "<<user_country[0]<<endl;
	
		cout<<" ________________________________________________________________________ "<<endl;
		cout<<"|            |                                                           |"<<endl;
		cout<<"| Index No.  |\t Missiles Names In Your Range"<<endl;
		cout<<"|------------|-----------------------------------------------------------|"<<endl;
	
		for(int i=0;i<7;i++){
				
			cout<<"|      "<<i<<"     |\t "<<palestine[i].name<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
			
		}
		cout<<"|____________|___________________________________________________________|"<<endl;

		do{
			cout<<"Enter The Index number Of Missile You Want To See More Details About: ";
			cin>>missile_no;
			if(missile_no>=7){
				cout<<"This Missile Is Not Available "<<endl;
				cout<<"Enter Again"<<endl;
			}else{
		
				cout<<" ________________________________________________________________________ "<<endl;
				cout<<"|            |                                                           |"<<endl;
				cout<<"|  Country   |\t"<<user_country[0]<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  Missile   |\t"<<palestine[missile_no].name<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  Range     |\t"<<palestine[missile_no].range<<" KM"<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  Speed     |\t"<<palestine[missile_no].mach_speed<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  KM/h      |\t"<<palestine[missile_no].speed<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  Status    |\t"<<palestine[missile_no].status<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  Type      |\t"<<palestine[missile_no].type<<endl;
				cout<<"|____________|___________________________________________________________|"<<endl;
			}
		}while(missile_no>=7);

	}
	if(user_country[0]==specific_countries[11]){  //israel
	
		cout<<"your country is "<<user_country[0]<<endl;
	
		cout<<" ________________________________________________________________________ "<<endl;
		cout<<"|            |                                                           |"<<endl;
		cout<<"| Index No.  |\t Missiles Names In You Range"<<endl;
		cout<<"|------------|-----------------------------------------------------------|"<<endl;
	
		for(int i=0;i<7;i++){
				
			cout<<"|      "<<i<<"     |\t "<<israel[i].name<<endl;
			cout<<"|------------|-----------------------------------------------------------|"<<endl;
			
		}
		cout<<"|____________|___________________________________________________________|"<<endl;

		do{
			cout<<"Enter The Index number Of Missile You Want To See More Details About: ";
			cin>>missile_no;
			if(missile_no>=7){
				cout<<"This Missile Is Not Available "<<endl;
				cout<<"Enter Again"<<endl;
			}else{
		
				cout<<" ________________________________________________________________________ "<<endl;
				cout<<"|            |                                                           |"<<endl;
				cout<<"|  Country   |\t"<<user_country[0]<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  Missile   |\t"<<israel[missile_no].name<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  Range     |\t"<<israel[missile_no].range<<" KM"<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  Speed     |\t"<<israel[missile_no].mach_speed<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  KM/h      |\t"<<israel[missile_no].speed<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  Status    |\t"<<israel[missile_no].status<<endl;
				cout<<"|------------|-----------------------------------------------------------|"<<endl;
				cout<<"|  Type      |\t"<<israel[missile_no].type<<endl;
				cout<<"|____________|___________________________________________________________|"<<endl;
			}
		}while(missile_no>=7);

	}

					
}
		////////////////////////////////////////////////////////////////////////////////////////////////




class Coordinates{
	private:
	    string place1;
	    double lon1;
	    double lat1;
	    string place2;
	    double lon2;
	    double lat2;
	    double distance;
	public:
				///////////////////// default construcor construcor /////////////////////
		Coordinates(){ 
		}
				///////////////////// parameterized construcor /////////////////////
				
		Coordinates(string p1, double latitude1, double longitude1, string p2, double latitude2, double longitude2){
			place1=p1;
		    lon1=longitude1;
		    lat1=latitude1;
		    place2=p2;
		    lon2=longitude2;
		    lat2=latitude2;
		}	
				///////////////////// overlooading construcor /////////////////////
		Coordinates(string p1, int latitude1, int longitude1, string p2, int latitude2, int longitude2){
			place1=p1;
		    lon1=longitude1;
		    lat1=latitude1;
		    place2=p2;
		    lon2=longitude2;
		    lat2=latitude2;
		}
				///////////////////// copy construcor /////////////////////
		Coordinates(Coordinates& copy){
			place1=copy.place1;
		    lon1=copy.lon1;
		    lat1=copy.lat1;
		    place2=copy.place2;
		    lon2=copy.lon2;
		    lat2=copy.lat2;
		}	
		
		
		
		void inputdata(){
														///////// Ist Place  input ///////////
				cout<<"Enter Place 1 Name :";
				cin>>place1;
				
				
				
				cout<<"Enter latitudes of "<<place1<<" :";
				for(int i=0;i<1;i++){
					
					
					for(int i=0;i<1;i++){            //////// cc type  /////////
					
			    		cin>>lat1; 
			    		if(lat1==isalpha(lat1)){
			    		cout<<"\nInput is Invalid"<<endl;
			    		cout<<"Enter Again :";
						cin.clear();
			    		cin.ignore();
			    		i--;
						}
						
					}
			
					if (lat1<-90 || lat1>90){
						cout<<"Your Entered Longitudes of "<<place1<<" Is Invalid"<<endl;
						cout<<"Because longitudes Must Be Greater than greater than 0 and less than and equal 180"<<endl;
						cout<<"\aSo Enter Again"<<endl;
						i--;
						break;
					}
				}
				
				cout<<"Enter longitudes of "<<place1<<" :";
				for(int i=0;i<1;i++){
					
			
					for(int i=0;i<1;i++){            //////// cc type  /////////
			    		
						
						cin>>lon1;
			    		if(lon1==isalpha(lon1)){
			    		cout<<"\nInput is Invalid"<<endl;
			    		cout<<"Enter Again :";
						cin.clear();
			    		cin.ignore();
			    		i--;
						}
					}
			
					if (lon1<-180 || lon1>180){
						cout<<"Your Entered longitudes of "<<place1<<" Is Invalid"<<endl;
						cout<<"Because longitudes Must Be Greater than greater than -180 and less than or equal 180"<<endl;
						cout<<"\aSo Enter Again"<<endl;
						i--;
						break;
					}
				}
				
												///////// Second Place  input ///////////
				
				cout<<"Enter Place 2 Name :";
				cin>>place1;
				
				
				
				cout<<"Enter latitudes of "<<place2<<" :";
				for(int i=0;i<1;i++){
					
					
					for(int i=0;i<1;i++){            //////// cc type  /////////
					
			    		cin>>lat2; 
			    		if(lat2==isalpha(lat2)){
			    		cout<<"\nInput is Invalid"<<endl;
			    		cout<<"Enter Again :";
						cin.clear();
			    		cin.ignore();
			    		i--;
						}
						
					}
			
					if (lat2<-90 || lat2>90){
						cout<<"Your Entered longitudes of "<<place1<<" Is Invalid"<<endl;
						cout<<"Because longitudes Must Be Greater than greater than -90 and less than and equal 90"<<endl;
						cout<<"\aSo Enter Again"<<endl;
						i--;
						break;
					}
				}
				
				cout<<"Enter longitudes of "<<place2<<" :";
				for(int i=0;i<1;i++){
					
			
					for(int i=0;i<1;i++){            //////// cc type  /////////
			    		cin>>lon2; 
			    		if(lon2==isalpha(lon2)){
			    		cout<<"\nInput is Invalid"<<endl;
			    		cout<<"Enter Again :";
						cin.clear();
			    		cin.ignore();
			    		i--;
						}
					}
			
					if (lon1<-180 || lon1>180){
						cout<<"Your Entered longitudes of "<<place1<<" Is Invalid"<<endl;
						cout<<"Because longitudes Must Be Greater than greater than -90 and less than and equal 90"<<endl;
						cout<<"\aSo Enter Again"<<endl;
						i--;
						break;
					}
				}
			
	
		}
		

	double distanceCalculate(){
		
		distance = formula_for_distance(lat1, lon1, lat2, lon2);
		return distance;
		
	}
	
	void display(){
		
		
		cout<<" __________________________________________________________________________ "<<endl;
		cout<<"|                                                                          |"<<endl;
		cout<<"|                               Place 1 Detail                             |"<<endl;
		cout<<"|                                                                          |"<<endl;		
		cout<<"|--------------------------------------------------------------------------|"<<endl;		
		cout<<"|  Address#1   |\t"<<place1<<endl;		
		cout<<"|--------------|-----------------------------------------------------------|"<<endl;	
		cout<<"|  Latitudes   |\t"<<lat1<<endl;	
		cout<<"|--------------|-----------------------------------------------------------|"<<endl;
		cout<<"|  Longitudes  |\t"<<lon1<<endl;
		cout<<"|______________|___________________________________________________________|"<<endl;
		cout<<"|                                                                          |"<<endl;
		cout<<"|                               Place 2 Detail                             |"<<endl;
		cout<<"|                                                                          |"<<endl;		
		cout<<"|--------------------------------------------------------------------------|"<<endl;		
		cout<<"|  Address#2   |\t"<<place2<<endl;		
		cout<<"|--------------|-----------------------------------------------------------|"<<endl;		
		cout<<"|  Latitudes   |\t"<<lat2<<endl;	
		cout<<"|--------------|-----------------------------------------------------------|"<<endl;
		cout<<"|  Longitudes  |\t"<<lon2<<endl;
		cout<<"|______________|___________________________________________________________|"<<endl;
		cout<<"|                                                                          |"<<endl;
		cout<<"|               Distance Between Place1 and Place 2                        |"<<endl;
		cout<<"|                                                                          |"<<endl;		
		cout<<"|--------------------------------------------------------------------------|"<<endl;	
		cout<<"|              |                                                           |"<<endl;	
		cout<<"|  Distance    |\t"<<distance<<" KM " << endl;
		cout<<"|              |                                                           |"<<endl;	
		cout<<"|______________|___________________________________________________________|"<<endl;
	}
	
    friend class case4;
};

class case4 {
public:
	Coordinates obj1;  //// for default constructor
	Coordinates obj2;  //// for parameterized constructor
	Coordinates obj3;  //// for overloading constructor
	Coordinates obj4;  //// for copy constructor
public:
	case4(): obj2("Islamabad",33.6995,73.0363,"Lahore",31.5204,74.3587) ,obj3("Islamabad",30,70,"Lahore",35,70){
		obj4=obj2;
	}
    
    void constructors(){
    	while(true){
    		char choice;
    		cout<<"1. ENTER MANUAL VALUES (USE DEFAULT CONSTRUCTOR)"<<endl;
    		cout<<"2. PARAMETIC VALUES (USE PARAMETERIZED CONSTRUCTOR)"<<endl;
    		cout<<"3. PARAMETERIC OVERLOADING VALUES (USE PARAMETIC CONSTRUCTOR)"<<endl;
    		cout<<"4. DUPLICATE VALUES(USE COPY CONSTRUCTOR)"<<endl;
    		cout<<"5. EXIT"<<endl;
    		cin>>choice;
    		
    		try{
				if(!isdigit(choice)){
				throw choice;
				}
				cout<<"Input Is Integer "<<endl;
			}
			catch(char){
				cout<<"Input Is Not Integer"<<endl;
			}
			
    		switch(choice){
    			case '1':
    				obj1.inputdata();
    				obj1.distanceCalculate();
    				obj1.display();
    				break;
    				
    			case '2':
    				obj2.distanceCalculate();
    				obj2.display();
    				break;
    				
    			case '3':
    				obj3.distanceCalculate();
    				obj3.display();
    				break;
    				
    			case '4':
    				obj4.distanceCalculate();
    				obj4.display();
    				break;
    				
    			case '5':
    				return;
    				
    			default:
    				cout<<"Enter Correct Integer "<<endl;
			}
		}
	}
};


				////////////// Password Validaton Classes //////////////

class Password_types{
	private:
		string username;
		string password;
	public:
		friend class pin_pass;
		friend class simple_pass;	
};

class pin_pass{
	private:
		
		Password_types p;
		
	public:
		pin_pass(){
			p.username="UIIT";
			p.password="1234";
		}
		
		void getPass(){
			
			string getuser;
			string getpass;
			bool user_verify;
			bool pass_verify;
			int attempt_count=4;
			
			cout<<"Enter UserName : ";
			
			while(user_verify==false){
				cin>>getuser;
				if(getuser==p.username){
					user_verify=true;
					
				}else if(getuser.length()<4 || getuser.length()>4){
					user_verify==false;
					cout<<"Length of USERNAME Must be 4"<<endl;
					cout<<"Enter Again UserName : ";
				}else if(getuser!=p.username){
					user_verify==false;
					cout<<"USERNAME INVALID."<<endl;
					cout<<"Enter Again UserName : ";
				}
			}
			
			cout<<"Enter Password : ";
			while(pass_verify==false ){
				cin>>getpass;
				
				bool alpha_check=false;
				
				for(int i=0;i<getpass.length();i++){
					char c=getpass[i];
					if(isalpha(c)){
						alpha_check=true;
						break;
					}
				}
				
				if(getpass==p.password){
					pass_verify=true;
					cout<<"Access Granted "<<endl;
				}else if(attempt_count==1){
					cout<<"Several Of Your Attempts Were Unsuccessful "<<endl;
					cout<<"So Access Denied "<<endl;
					cout<<"Program Exiting ...................";
					exit(0);
					
				}else if(alpha_check==true){
					pass_verify==false;
					attempt_count--;
					cout<<"ALPHAPHET NOT ALLOW IN PIN PASSWORD "<<endl;
					cout<<"Remaining Attempt : "<<attempt_count<<endl;
					cout<<"Enter Again PASSWORD : ";
				}else if(getpass.length()<4 || getuser.length()>4){
					pass_verify==false;
					attempt_count--;
					cout<<"Length of PASSWORD Must be 4"<<endl;
					cout<<"Remaining Attempt : "<<attempt_count<<endl;
					cout<<"Enter Again PASSWORD : ";
				}else if(getpass!=p.password){
					pass_verify==false;
					attempt_count--;
					cout<<"PASSWORD INVALID."<<endl;
					cout<<"Remaining Attempt : "<<attempt_count<<endl;
					cout<<"Enter Again PASSWORD : ";
				}
				

			}
		}
		
};

class simple_pass{
	private:
		
		Password_types p;
		
	public:
		simple_pass(){
			p.username="UIIT";
			p.password="bsse2a";	
		}
		
		void getPass(){
			
			string getuser;
			string getpass;
			bool user_verify;
			bool pass_verify;
			int attempt_count=4;
			
			cout<<"Enter UserName : ";
			
			while(user_verify==false){
				cin>>getuser;
				if(getuser==p.username){
					user_verify=true;
					
				}else if(getuser.length()<4 || getuser.length()>4){
					user_verify==false;
					cout<<"Length of USERNAME Must be 4"<<endl;
					cout<<"Enter Again UserName : ";
				}else if(getuser!=p.username){
					user_verify==false;
					cout<<"USERNAME INVALID."<<endl;
					cout<<"Enter Again UserName : ";
				}
			}
			
			cout<<"Enter Password : ";
			while(pass_verify==false ){
				cin>>getpass;
				if(getpass==p.password){
					pass_verify=true;
					cout<<"Access Granted "<<endl;
				}else if(attempt_count==1){
					cout<<"Several Of Your Attempts Were Unsuccessful "<<endl;
					cout<<"So Access Denied "<<endl;
					cout<<"Program Exiting ...................";
					exit(0);
					
				}else if(getpass.length()<6 || getuser.length()>6){
					pass_verify==false;
					attempt_count--;
					cout<<"Length of PASSWORD Must be 6"<<endl;
					cout<<"Remaining Attempt : "<<attempt_count<<endl;
					cout<<"Enter Again PASSWORD : ";
				}else if(getpass!=p.password){
					pass_verify==false;
					attempt_count--;
					cout<<"PASSWORD INVALID."<<endl;
					cout<<"Remaining Attempt : "<<attempt_count<<endl;
					cout<<"Enter Again PASSWORD : ";
				}
				

			}
		}
		
};

class Login{
	private:
		
		pin_pass obj1;
		simple_pass obj2;
		
	public:
		void systemLogin(){
			
			int choice;
			while(true){
				cout<<"LOGIN REQUIRED"<<endl;
				cout<<"Choose Your Login Method"<<endl;
				cout<<"1. Using PIN CODE "<<endl;
				cout<<"2. Using PASSWORD "<<endl;
				cout<<"3. EXIT "<<endl;
			//	cin>>choice;
				for(int i=0;i<1;i++){
		    		cin>>choice;
		    		if(choice==isalpha(choice)){
			    		cout<<"\Invalid Input. Please Enter a Number: ";
						cin.clear();
			    		cin.ignore();
			    		i--;
					}
				}
				
				switch(choice){
					case 1:
						obj1.getPass();
						cout<<"LOGIN SUCCESSFULLY"<<endl;
						return;
						break;
					case 2:
						obj2.getPass();
						cout<<"LOGIN SUCCESSFULLY"<<endl;
						return;
						break;
//					case 3:					////////// USE THIS CASE IF CONTINUE WITHOUT LOGIN //////////
//						cout<<"Process Continued Without Login "<<endl;
//						return;
//						break;
					case 3:
						cout<<"Program Exiting ....";
						exit(0);
						break;
					default:
						cout<<"INVALID INPUT "<<endl;
				}
			}
			
		}
};
		////////////////////////////////////////////////////////////////////////////
	
class Menu{
public:
    void display() {
		cout<<"\t\t\t\t\t __________________________________________________"<<endl;
		cout<<"\t\t\t\t\t|================= BSSE-2A EVEVNING ===============|"<<endl;
		cout<<"\t\t\t\t\t|================= Semester Project ===============|"<<endl;
		cout<<"\t\t\t\t\t|================= DEFENSE SYSTEM =================|"<<endl;
		cout<<"\t\t\t\t\t|=================      MENU      =================|"<<endl;
		cout<<"\t\t\t\t\t|--------------------------------------------------|"<<endl;
	    cout<<"\t\t\t\t\t| Select Any Option:                               |"<<endl;
		cout<<"\t\t\t\t\t|--------------------------------------------------|"<<endl;    
	    cout<<"\t\t\t\t\t| 1. Offensive Strike / Defensive Strategy.        |"<<endl;
		cout<<"\t\t\t\t\t|--------------------------------------------------|"<<endl;
	    cout<<"\t\t\t\t\t| 2. Read and write missile data(file handling).   |"<<endl;
		cout<<"\t\t\t\t\t|--------------------------------------------------|"<<endl;    
	    cout<<"\t\t\t\t\t| 3. Analysis Defense System Of Specific Country.  |"<<endl;
		cout<<"\t\t\t\t\t|--------------------------------------------------|"<<endl;    
	    cout<<"\t\t\t\t\t| 4. Distance Find For any Place                   |"<<endl;
		cout<<"\t\t\t\t\t|--------------------------------------------------|"<<endl;    
		cout<<"\t\t\t\t\t| 5. Exit Program                                  |"<<endl;
		cout<<"\t\t\t\t\t|--------------------------------------------------|"<<endl;    
		cout<<"\t\t\t\t\t|__________________________________________________|"<<endl;
    }
};

class Application {
public:
    void run() {
        Menu menu;
        int choice;
        Login required;
        required.systemLogin();
        while (true) {
            menu.display();
            cout << "Enter your choice: ";

	        for(int i=0;i<1;i++){
	    		cin>>choice;
	    		if(choice==isalpha(choice)){
		    		cout<<"Invalid Input. Please Enter a Number: ";
					cin.clear();
		    		cin.ignore();
		    		i--;
				}
			}
		
//            cin >> choice;
//            if (cin.fail()) { // check if input is not an integer
//                cout << "Invalid Input. Please Enter a Number." << endl;
//                cin.clear();
//                cin.ignore();
//                continue;
//            }

            switch (choice) {
                case 1:{
              //  	Login required;
                    cout<<"\n\tOffensive Strike / Defensive Strategy\n"<<endl;
                //    required.systemLogin();
                	case1 *c= new case1;
					c->userCityInfo();
					c->enemyCityInfo();
					c->distanceCalculate();
                	break;
                }
                case 2:{
               // 	Login required;
                    cout<<"\n\tRead and Write Missile Data (File Handling)\n"<<endl;
                //    required.systemLogin();
                    case2 *c1 = new case2();
                    c1->filehandling();
                    break;
                 }
                case 3:{
                    cout<<"\n\tAnalysis Defense System Of Specific Country\n" <<endl;
	            	case3 *b=new case3;
//	            	b->displaydata();
	            	do{
			    		int choice;
			    		cout<<"1. Select Country"<<endl;
			    		cout<<"2. EXIT"<<endl;
			    		cin>>choice;
			    		switch(choice){
			    			case 1:
			    				b->displaydata();
			    				break;
			    			default:
			    				cout<<endl;
						}
					}while(choice==1);
					
                    break;
                }
                case 4:{
                    cout<<"\n\tDistance Find For any Place\n"<<endl;
                	case4 obj;
					obj.constructors();                 
                   
                    break;
                }
                case 5:{
                    cout<<"Exiting program..."<<endl;
                    cout<<"Program terminated successfully."<<endl;
                    exit(0);
                    break;
                }
                default:
                    cout<<"\nChoose Right Menu Option"<<endl;
                    break;
            }
        }
    }
};
		 

int main(){
	Application app;
    app.run();
    
	return 0;
}
