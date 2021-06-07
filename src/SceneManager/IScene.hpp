/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** IScene
*/

#ifndef ISCENE_HPP_
#define ISCENE_HPP_

namespace Interfaces {
	class IScene {
		public:
			enum sceneId {
				GAME = true,
				MENU = true,
				SETTINGS = true,
				LOAD = true,
				PAUSE = true,
				QUIT = true
			};
			virtual ~IScene() = default;
			virtual sceneId run() = 0;
	};
}

#endif /* !ISCENE_HPP_ */
