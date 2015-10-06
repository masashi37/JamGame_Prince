
#pragma once

#include <iostream>
#include <fstream>
#include "lib/random.hpp"


//�E�B���h�E�T�C�Y
enum Window {
	WIDTH = 2000,
	HEIGHT = 1000,
};

//�V�[���̖��O
enum SceneName {
	TITLE,
	SELECT,
	GAME,
	RESULT,
};

//�I�u�W�F�N�g�̏��
struct ObjectBace {
	Vec2f pos;
	Vec2f size;
};
struct TextureObject :ObjectBace {
	Vec2f cut_pos;
	Vec2i cut_size;
	Texture pic;
};



/*

//�L�����̏ꏊ����
enum PlayerMode {
GROUND,
AIR
};

//�L�����̃��[�h
enum CharaMode {
NORMAL,		//�m�[�}��
JUMP,		//�W�����v
NONE,		//�Ȃ�
};

//�d��
const float gravity = -1.0f;
const float gravity_max = -6.0f;

//�L�����̍ő吔
const int CHARA_MAX = 6;

//�\����
//-----------------------------------------------------------------------------------------------

//�L�����̃f�[�^
struct CharaState {
Vec2f pos;
float size;
Vec2f speed;
float jump_power;
int mode;

Vec2f cut_pos;
Vec2f cut_size;
Color color;
};

CharaState chara[CHARA_MAX];

struct MusicFlag{
bool title_music_flag,
stage_music1_flag,
stage_music2_flag,
result_music_flag,
item_se_up_flag,
item_se_down_flag,
select_se_decide_flag,
select_se_finaldecide_flag,
select_se_select_flag;
};
MusicFlag music_flag;

//�ϐ�
//---------------------------------------------------------------------------------------------





//�V�[���؂�ւ��̃X�C�b�`
int scene_mover = 0;


//�ꎞ��~�̐؂�ւ�
bool is_stop_time = false;

//�L�����ύX
int select_chara_number = 0;

//�����_��
Random random;
int rand_seed = 0;


//�w�i�ړ�
int back_sift = 0;

//�X�s�[�h�A�b�v
bool is_change = false;
int change_count = 0;

//�X�s�[�h�_�E��
bool is_down = false;
int down_count = 0;

const float map_speed = 5.0f;	//�}�b�v�̑��x


//�}�b�v
//-------------------------------------------------------------------------------------------


//txt�}�b�v�`�b�v
//�}�b�v�l�[��(No)
enum {
MAP_TYPE01,
MAP_TYPE02,
MAP_TYPE03,
MAP_TYPE04,
MAP_TYPE05,
MAP_TYPE06,
MAP_TYPE07,
MAP_TYPE08,
MAP_TYPE09,
MAP_TYPE10,
MAP_TYPE_GOAL,
MAP_TYPE_END,
MAP_TYPE_END2,

MAP_TEXT_MAX,
};
std::ifstream* map_type_list[MAP_TEXT_MAX];


//mapChip�̃f�[�^
struct MapData {
Vec2f pos;
float size;
int id;

Vec2f cut_pos;
Vec2f cut_size;
};

//�u���b�N��
enum BlockNumber {
LENGTH = 10,
WIDE = 10,
};
MapData maps[MAP_TEXT_MAX][LENGTH][WIDE];

//�u���b�N�^�C�v(No)
enum BlockType {
AIR_BLOCK,  //0
FLOOR,		//1
BLOCK,		//2
CHANGE_ITEM, //3
CONCRETE,	//4
REDCAPET,	//5
GOAL,
GOAL_PRINCE,

DOWN_BLOCK,	//8
};


//�}�b�v���炵��񂾂��ǂݍ��݃t���O
struct map_dis_flag{
bool type1,
type2,
type3,
type4,
type5,
type6,
type7,
type8,
type9,
type10;
};

map_dis_flag dismap;



//�}�b�v�̃^�C�v������
void mapTypeInit() {

const char* text_name[MAP_TEXT_MAX]{
"res/mapType/map_type01.txt",
"res/mapType/map_type02.txt",
"res/mapType/map_type03.txt",
"res/mapType/map_type04.txt",
"res/mapType/map_type05.txt",
"res/mapType/map_type06.txt",
"res/mapType/map_type07.txt",
"res/mapType/map_type08.txt",
"res/mapType/map_type09.txt",
"res/mapType/map_type10.txt",
"res/mapType/map_typeGOAL.txt",
"res/mapType/map_type_end.txt",
"res/mapType/map_type_end.txt",

};
for (int index = 0; index < MAP_TEXT_MAX; ++index) {
map_type_list[index] = new std::ifstream(text_name[index]);
}
dismap.type1 = false;
dismap.type2 = false;
dismap.type3 = false;
dismap.type4 = false;
dismap.type5 = false;
dismap.type6 = false;
dismap.type7 = false;
dismap.type8 = false;
dismap.type9 = false;
dismap.type10 = false;

}




//�}�b�v�̏�����
void mapChipInit() {

for (int k = 0; k < MAP_TEXT_MAX; k++){
for (int y = 0; y < LENGTH; y++) {
for (int x = 0; x < WIDE; x++) {

maps[k][y][x].size = 100;

maps[k][y][x].pos.x() =
(-WIDTH + maps[k][y][x].size * x + k * 1000) +
(maps[k][y][x].size * 10);
maps[k][y][x].pos.y() =
HEIGHT / 2 - maps[k][y][x].size * y - maps[k][y][x].size;

maps[k][y][x].cut_pos.x() = maps[k][y][x].cut_pos.y() = 0;
maps[k][y][x].cut_size.x() = maps[k][y][x].cut_size.y() = 512;

}
}


}

}



//�摜
//--------------------------------------------------------------------------------------------------------------

//�摜�̖��O(No)
enum {
RED_ZUKIN,
MUCH,
ALICE,
SNOW_WHITE,
KAGUYA,
CINDERELLA,

RED_ZUKIN_EVO,
MUCH_EVO,
ALICE_EVO,
SNOW_WHITE_EVO,
KAGUYA_EVO,
CINDERELLA_EVO,

PRINCE,

CHARA_PIC_MAX,
};
Texture* chara_list[CHARA_PIC_MAX];

//���U���g�摜�̖��O(No)
enum {
RED_ZUKIN_LOSE,
MUCH_LOSE,
ALICE_LOSE,
WHITE_SNOW_LOSE,
KAGUYA_LOSE,
CINDERELLA_LOSE,

RESULT_PIC_MAX,
};
Texture* result_list[RESULT_PIC_MAX];

//�G�t�F�N�g
Texture dash_effect;
//�u���b�N
Texture floor_block;
Texture ground_block;
Texture item_block;
Texture concrete_block;
Texture redcapet;
Texture speed_down;

//�w�i
Texture title_background;
Texture game_bg_forest;
//�X�e�[�W�w�i
Texture town_day;
Texture town_night;
Texture forest;
Texture castle_start;
Texture gate;
Texture castle;
Texture banner;


//�Q�[���I�[�o�[
Texture clear_bg;



const int image_size_bg_width = 1024;
const int image_size = 512;

//�����֘A�摜
enum SENTENCE{
CHARACTERSELECT,
GAMESTART,
MODESELECT,
ORDER,
TIMEATTACK,

TITLE_SEN,

ZUKIN_SEN,
MUCH_SEN,
ALICE_SEN,
SNOW_WHITE_SEN,
KAGUYA_SEN,
CINDERELLA_SEN,
SENTENCE_MAX,
};
Texture* sentence_list[SENTENCE_MAX];

//�摜�̏�����
void textureInit() {

const char* text_name[CHARA_PIC_MAX]{
"res/Image/Character/red_zukin.png",
"res/Image/Character/much.png",
"res/Image/Character/alice.png",
"res/Image/Character/snow_white.png",
"res/Image/Character/kaguya.png",
"res/Image/Character/cinderella.png",

"res/Image/Character/red_zukin_evo.png",
"res/Image/Character/much_evo.png",
"res/Image/Character/alice_evo.png",
"res/Image/Character/snow_white_evo.png",
"res/Image/Character/kaguya_evo.png",
"res/Image/Character/cinderella_evo.png",


"res/Image/Character/prince.png"
};
for (int index = 0; index < CHARA_PIC_MAX; ++index) {
chara_list[index] = new Texture(text_name[index]);
}

title_background = Texture("res/Image/Background/title_bg.png");
dash_effect = Texture("res/Image/Effect/dash_effect.png");
floor_block = Texture("res/Image/Block/block_grass.png");
ground_block = Texture("res/Image/Block/block_brown.png");
item_block = Texture("res/Image/Block/stekki.png");
concrete_block = Texture("res/Image/Block/conkuri.png");
redcapet = Texture("res/Image/Block/redcapet.png");
speed_down = Texture("res/Image/UI/selecticon.png");

town_day = Texture("res/Image/Background/haikei_jouka_asa.png");
town_night = Texture("res/Image/Background/haikei_jouka_yuugata.png");
forest = Texture("res/Image/Background/forest_bg.png");
castle_start = Texture("res/Image/Background/haikei_siro.png");
gate = Texture("res/Image/Background/gate.png");
castle = Texture("res/Image/Background/haikei_siro_roop.png");
banner = Texture("res/Image/Background/oudanmaku.png");

clear_bg = Texture("res/Image/ED/kuria.png");

const char* sentence_name[SENTENCE_MAX]{
"res/Image/Sentence/characterselect.png",
"res/Image/Sentence/gamestart.png",
"res/Image/Sentence/modeselect.png",
"res/Image/Sentence/order.png",
"res/Image/Sentence/timeattack.png",
"res/Image/Sentence/title.png",
"res/Image/Sentence/red_zukin.png",
"res/Image/Sentence/much.png",
"res/Image/Sentence/alice.png",
"res/Image/Sentence/snow_white.png",
"res/Image/Sentence/kaguya.png",
"res/Image/Sentence/cinderella.png",
};

for (int index = CHARACTERSELECT; index < SENTENCE_MAX; ++index) {
sentence_list[index] = new Texture(sentence_name[index]);
}



}




//���y�֘A
//----------------------------------------------------

enum MediaName{
TITLE_MUSIC,
STAGE_MUSIC1,
STAGE_MUSIC2,
RESULT_MUSIC,
ITEM_SE_UP,
ITEM_SE_DOWN,
SELECT_SE_DECIDE,
SELECT_SE_FINALDECIDE,
SELECT_SE_SELECT,

MUSIC_LIST

};
Media* music_list[MUSIC_LIST];

void musicInit(){

const char* music_name[MUSIC_LIST]{
"res/Music/BGM/title/title.wav",
"res/Music/BGM/stage/stage1.wav",
"res/Music/BGM/stage/stage2.wav",
"res/Music/BGM/result/goal_No1.wav",
"res/Music/SE/item/item_speedup.wav",
"res/Music/SE/item/item_speeddown.wav",
"res/Music/SE/select/decide.wav",
"res/Music/SE/select/final_decide.wav",
"res/Music/SE/select/select.wav",
};
for (int index = 0; index < MUSIC_LIST; ++index){
music_list[index] = new Media(music_name[index]);
}
//�t���O������
music_flag.title_music_flag = false;
music_flag.stage_music1_flag = false;
music_flag.stage_music2_flag = false;
music_flag.result_music_flag = false;
music_flag.item_se_up_flag = false;
music_flag.item_se_down_flag = false;
music_flag.select_se_decide_flag = false;
music_flag.select_se_finaldecide_flag = false;
music_flag.select_se_select_flag = false;
}

//�֐�
//----------------------------------------------------



//���Ɣ��̓����蔻��
bool boxCollision(
Vec2f box_pos, Vec2f box_size,
Vec2f box1_pos, Vec2f box1_size) {

return (
box_pos.x() < box1_pos.x() + box1_size.x() &&
box_pos.x() + box_size.x() > box1_pos.x() &&
box_pos.y() < box1_pos.y() + box1_size.y() &&
box_pos.y() + box_size.y() > box1_pos.y());
}

void box_box(Vec2f pos, Vec2f pos_size, Vec2f box, Vec2f box_pos){

if (pos.x() + pos_size.x() > box.x()){
pos.x() += pos.x() + pos_size.x() - box.x();
}




}

//�L�����̏����l
void charaInit() {
for (int i = 0; i < CHARA_MAX; ++i) {

chara[i] = {
Vec2f(0, -100),
100,
Vec2f(0.0f, 0.0f),
20.0f,
NORMAL,
Vec2f(0, 0),
Vec2f(512, 512),
Color::white
};

}
}




void charaMove(AppEnv& env){


for (int i = 0; i < CHARA_MAX; ++i) {
if (chara[i].speed.y() <= gravity_max){
chara[i].speed.y() = gravity_max;
}
else{
chara[i].speed.y() += gravity;
}

chara[i].pos.y() += chara[i].speed.y();

std::cout << chara[i].speed.y() << std::endl;

for (int k = 0; k < MAP_TEXT_MAX; k++){
for (int y = 0; y < LENGTH; y++) {
for (int x = 0; x < WIDE; x++) {

if (maps[k][y][x].id == FLOOR || maps[k][y][x].id == BLOCK || maps[k][y][x].id == REDCAPET || maps[k][y][x].id == CONCRETE ){
if (chara[i].pos.x() > maps[k][y][x].pos.x() &&
chara[i].pos.x() < maps[k][y][x].pos.x() + maps[k][y][x].size&&
chara[i].pos.y() > maps[k][y][x].pos.y() + maps[k][y][x].size / 2 &&
chara[i].pos.y() < maps[k][y][x].pos.y() + maps[k][y][x].size) {

chara[i].pos.y() = maps[k][y][x].pos.y() + maps[k][y][x].size;
chara[i].speed.y() = 0;

if (maps[k][y - 1][x + 1].id == FLOOR && maps[k][y][x + 1].id == BLOCK || maps[k][y][x].id == REDCAPET || maps[k][y][x].id == CONCRETE){
--y;
++x;
}
}

if (chara[i].pos.x() > maps[k][y][x].pos.x() &&
chara[i].pos.x() < maps[k][y][x].pos.x() + maps[k][y][x].size&&
chara[i].pos.y() > maps[k][y][x].pos.y() &&
chara[i].pos.y() < maps[k][y][x].pos.y() + maps[k][y][x].size / 2) {

chara[i].pos.y() = maps[k][y][x].pos.y() - maps[k][y][x].size;
chara[i].speed.y() = 0;

}

if (chara[i].pos.x() + chara[i].size > maps[k][y][x].pos.x() &&
chara[i].pos.x() + chara[i].size < maps[k][y][x].pos.x() + maps[k][y][x].size &&
chara[i].pos.y() >= maps[k][y][x].pos.y() &&
chara[i].pos.y() < maps[k][y][x].pos.y() + maps[k][y][x].size) {

chara[i].pos.x() = maps[k][y][x].pos.x() - chara[i].size;

}
}

if (maps[k][y][x].id == CHANGE_ITEM) {
if (boxCollision(
chara[i].pos, Vec2f(chara[i].size, chara[i].size),
maps[k][y][x].pos, Vec2f(maps[k][y][x].size, maps[k][y][x].size))) {

is_change = true;

}
}

if (maps[k][y][x].id == DOWN_BLOCK) {
if (boxCollision(
chara[i].pos, Vec2f(chara[i].size, chara[i].size),
maps[k][y][x].pos, Vec2f(maps[k][y][x].size, maps[k][y][x].size))) {


//is_down = true;

}
}
}
}
}


if (is_change == true){
change_count++;
if (change_count > 180){
is_change = false;
change_count = 0;
}

chara[i].pos.x() += 5;
}
if (is_down == true){
down_count++;
if (down_count > 120){
is_down = false;
down_count = 0;
}
chara[i].pos.x() -= 3;
}

if (env.isPushKey(GLFW_KEY_SPACE) || env.isPushKey('C')){
chara[select_chara_number].speed.y() = chara[select_chara_number].jump_power;
}
}
}

*/