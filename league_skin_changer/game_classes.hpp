/* This file is part of LeagueSkinChanger by b3akers, licensed under the MIT license:
*
* MIT License
*
* Copyright (c) b3akers 2020
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
#pragma once
#include <vector>
#include <cinttypes>
#include <string>
#include <memory>
#include <map>
#include <unordered_map>

#include "offsets.hpp"

#define CONCAT_IMPL(x, y) x##y
#define MACRO_CONCAT(x, y) CONCAT_IMPL(x, y)
#define PAD(SIZE) uint8_t MACRO_CONCAT(_pad, __COUNTER__)[SIZE];

template <size_t Index, typename ReturnType, typename... Args>
ReturnType call_virtual( void* instance, Args... args )
{
	using Fn = ReturnType( __thiscall* )( void*, Args... );

	auto function = ( *reinterpret_cast< Fn** >( instance ) )[ Index ];
	return function( instance, args... );
}

enum class GGameState_s : std::int32_t
{
	LoadingScreen = 0,
	Connecting = 1,
	Running = 2,
	Poaused = 3,
	Finished = 4,
	Exiting = 5
};


class GameClient
{
	PAD( 0x8 );
public:
	GGameState_s game_state;
};

class AString
{
public:
	const char* str;
	std::size_t length;
	std::size_t capacity;
};

class Skin
{
public:
	std::int32_t skin_id;
	AString skin_name;
};

class Champion
{
public:
	PAD(0x4);
	AString champion_name;
	PAD(0x88 - 0xC - 0x4);
	std::vector<Skin> skins;

};

class ChampionManager
{
	PAD(0x18);
public:
	std::vector<Champion*> champions;
};

class CharacterStackData
{
public:
	AString model;
	PAD(0xC);
	std::int32_t skin;
	PAD(0x44);
	std::int8_t gear;
	PAD(0x7)
};

class CharacterDataStack
{
public:
	std::vector<CharacterStackData> stack;
	CharacterStackData base_skin;

	void update( bool change );
	void push( const char* model, std::int32_t skin );
};

class r3dTexture;


class GameObject
{
public:
	std::string& name( ) { return *reinterpret_cast< std::string* >( std::uintptr_t( this ) + offsets::GameObject::Name ); }
	std::int32_t get_team( ) { return *reinterpret_cast< std::int32_t* >( std::uintptr_t( this ) + offsets::GameObject::Team ); }

};

class AIBaseCommon : public GameObject
{
public:
	CharacterDataStack* get_character_data_stack( ) { return reinterpret_cast< CharacterDataStack* >( std::uintptr_t( this ) + offsets::AIBaseCommon::CharacterDataStack ); }

	void change_skin( const char* model, std::int32_t skin );
};

class AITurret : public AIBaseCommon {
public:
};

class AIHero : public AIBaseCommon
{
public:

};

class AIMinionClient : public AIBaseCommon
{
public:
	AIBaseCommon* get_gold_redirect_target( );
	bool is_lane_minion( );
};

template <class T>
class ManagerTemplate
{
	PAD( 0x4 );
public:
	T** list;
	std::size_t length;
	std::size_t capacity;
};