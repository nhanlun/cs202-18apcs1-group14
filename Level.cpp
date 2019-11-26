#include "Level.h"

Level::Level(int noLevel, Screen& _sc) : lanes(2 * noLevel), gameState(State::RUN)
{
	player = new Player(15, 41);

	for (unsigned index = 0; index < lanes.size(); ++index)
	{
		Direction dir = Direction(3 - (index % 2) * 2);
		Type type = Type(rand() % int(Type::Count));
		int row = 32 - 7 * (index % 4);
		Color clr = Color(rand() % 9 + 7);

		Speed speed = Speed::SLOW;
		if (noLevel < 4 && noLevel > 1)
			speed = Speed(rand() % 3 + 2);
		else
			speed = Speed(rand() % 4 + 1);

		int spawnTime = 25;
		if (type == Type::BIRD) spawnTime = 15;
		spawnTime *= int(speed);

		lanes[index] = new Lane(_sc, dir, type, row, clr, spawnTime, speed);
	}
}

Level::~Level()
{
	for (auto const& lane : lanes) delete lane;
	delete player;
}

void Level::run(const Screen& sc)
{
	unsigned noLane = 1;

	while (noLane <= lanes.size())
	{
		system("cls");
		sc.displayMap();
		resetPlayer();

		std::vector<std::thread*> vThread;
		addThreadPlayer(vThread, sc);
		addThreadLanes(vThread, sc, noLane);
		runThreads(vThread);

		if (gameState == State::LOSE) break;
		else if (gameState == State::STOP) break;
	}

	yaosu::gotoXY(150, 15);
	if (gameState == State::WIN) std::cout << "YOU WIN";
	else if (gameState == State::LOSE) std::cout << "YOU LOSE";
}

void Level::resetPlayer()
{
	gameState = State::RUN;
	player->reset();
	player->display();
}

void Level::addThreadPlayer(std::vector<std::thread*>& vThread, const Screen& sc)
{
	vThread.push_back(new std::thread(&Player::play, player, std::ref(sc),
		&ioMtx, std::ref(gameState)));
}

void Level::addThreadLanes(std::vector<std::thread*>& vThread, const Screen& sc, 
	unsigned& noLane)
{
	//Add at most 4 next lanes
	for (int screenLane = 1; screenLane <= 4 && noLane <= lanes.size(); ++screenLane)
	{
		vThread.push_back(new std::thread(&Lane::run, lanes[noLane - 1],
			std::ref(sc), &ioMtx, std::ref(gameState), player));
		++noLane;
	}
}

void Level::runThreads(std::vector<std::thread*>& vThread)
{
	for (auto const& thread : vThread) thread->join();
	for (auto const& thread : vThread) delete thread;
}