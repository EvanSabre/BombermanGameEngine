/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** IScene
*/

#ifndef ISCENE_HPP_
#define ISCENE_HPP_

namespace gameEngine {
	namespace interfaces {
		class IScene {
			public:
				virtual ~IScene() = default;

				virtual void start() = 0;
				virtual void update() = 0;
		};
	}
}

#endif /* !ISCENE_HPP_ */
