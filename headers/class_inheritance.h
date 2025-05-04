#pragma once

class Base_Cd
{
protected:
	std::string performer = "noPerformers";
	std::string name_album = "noAlbum";
	int num_of_songs = 0;
	double playtime = 0.0;
public:
	Base_Cd(const std::string&, const std::string&, int, double);
	Base_Cd();
	~Base_Cd();
	virtual const void Report();
	Base_Cd& operator=(const Base_Cd&);
};

class Child_Classic : public Base_Cd
{
private:
	std::string name_main_song = "noNameSong";
public:
	Child_Classic() : Base_Cd() {};
	Child_Classic(const std::string& singer, const std::string& album, const std::string& main_song, int count_track, double duration) : Base_Cd(singer, album, count_track, duration) { this->name_main_song = main_song; };
	virtual const void Report();
	~Child_Classic();
};

Base_Cd::Base_Cd(const std::string& singer, const std::string& album, int count_track, double duration)
{
	this->performer = singer;
	this->name_album = album;
	this->num_of_songs = count_track;
	this->playtime = duration;
}

Base_Cd::Base_Cd()
{
	this->performer = "noPerformers";
	this->name_album = "noAlbum";
	this->num_of_songs = 0;
	this->playtime = 0.0;
}

Base_Cd::~Base_Cd()
{
	std::cout << "~destructor BASE in ON\n";
	this->performer = "noPerformers";
	this->name_album = "noAlbum";
	this->num_of_songs = 0;
	this->playtime = 0.0;
}

const void Base_Cd::Report()
{
	std::cout << "In BASE performer = " << this->performer << "\n";
	std::cout << "In BASE name_album = " << this->name_album << "\n";
	std::cout << "In BASE num_of_songs = " << this->num_of_songs << "\n";
	std::cout << "In BASE playtime = " << this->playtime << "\n\n";
}

Base_Cd& Base_Cd::operator=(const Base_Cd& right_side)
{
	this->performer = right_side.performer;
	this->name_album = right_side.name_album;
	this->num_of_songs = right_side.num_of_songs;
	this->playtime = right_side.playtime;

	return *this;
}

const void Child_Classic::Report()
{
	std::cout << "In CHILD performer = " << this->performer << "\n";
	std::cout << "In CHILD name_album = " << this->name_album << "\n";
	std::cout << "In CHILD num_of_songs = " << this->num_of_songs << "\n";
	std::cout << "In CHILD playtime = " << this->playtime << "\n";
	std::cout << "In CHILD name_main_song = " << this->name_main_song << "\n\n";
}

Child_Classic::~Child_Classic()
{
	std::cout << "~destructor CHILD in ON\n";
	this->performer = "noPerformers";
	this->name_album = "noAlbum";
	this->num_of_songs = 0;
	this->playtime = 0.0;
	this->name_main_song = "noNameSong";
}