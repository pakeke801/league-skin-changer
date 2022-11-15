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
#include "offsets.hpp"
namespace offsets {
	namespace global {
		std::uint32_t Player = 0x3157F40;
		std::uint32_t ChampionManager = 0x25095E0;
		std::uint32_t Riot__g_window = 0x3157F48;
		std::uint32_t ManagerTemplate_AIMinionClient_ = 0x25095CC;
		std::uint32_t ManagerTemplate_AIHero_ = 0x18BBF40;
		std::uint32_t ManagerTemplate_AITurret_ = 0x315089C;
		std::uint32_t GameClient = 0x25095E8;
	};

	namespace AIBaseCommon {
		std::uint32_t CharacterDataStack = 0x2D98;
		std::uint32_t SkinId = 0xF88;
	};

	namespace MaterialRegistry {
		std::uint32_t D3DDevice = 0x210;
		std::uint32_t SwapChain = 0x114;
	};

	namespace AIMinionClient {
		std::uint32_t IsLaneMinion = (0x3675 - 1);
	};

	namespace functions {
		std::uint32_t Riot__Renderer__MaterialRegistry__GetSingletonPtr = 0xAF4C90;
		std::uint32_t translateString_UNSAFE_DONOTUSE = 0x9C5E40;
		std::uint32_t CharacterDataStack__Push = 0x119260;
		std::uint32_t CharacterDataStack__Update = 0x107E70;
		std::uint32_t GetGoldRedirectTarget = 0x1598D0;
		std::uint32_t CharacterData__GetCharacterPackage = 0x6C5370;
	};
};