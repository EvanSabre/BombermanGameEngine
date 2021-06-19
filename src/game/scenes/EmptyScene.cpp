/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** EmptyScene
*/

#include "EmptyScene.hpp"

using namespace game::scenes;

EmptyScene::EmptyScene(std::shared_ptr<gameEngine::managers::WindowManager> &windowManager, const std::shared_ptr<game::managers::GameManager> &info)
: AScene(windowManager, info), _text("HELLO BITE", 10)
{
}

EmptyScene::~EmptyScene()
{
}

void EmptyScene::start()
{
    Vector<float> size(WINDOW_X / 2, WINDOW_Y / 1.5);
    Vector<float> pos(WINDOW_X / 4, WINDOW_Y / 7);

    std::array<std::shared_ptr<gameEngine::encapsulation::BModel>, 1> modelList =
    {
        std::make_shared<gameEngine::encapsulation::BModel>("./assets/Pirates/Models/Character.iqm", Vector3T<float>(3, 4, 0)),
        // std::make_shared<gameEngine::encapsulation::BModel>("./assets/Samurai/Models/Character.iqm", Vector3T<float>(3, 4, 0)),
        // std::make_shared<gameEngine::encapsulation::BModel>("./assets/Vikings/Models/Character.iqm", Vector3T<float>(3, 4, 0)),
    };

    _tmp = std::make_shared<gameEngine::encapsulation::BTexture2D>("./assets/Pirates/Textures/Character.png");
    // gameEngine::encapsulation::BTexture2D texture2("./assets/Samurai/Textures/Character.png");
    // gameEngine::encapsulation::BTexture2D texture3("./assets/Vikings/Textures/Character.png");

    modelList[0]->setTexture(0, MATERIAL_MAP_DIFFUSE, *_tmp);
    // modelList[1]->setTexture(0, MATERIAL_MAP_DIFFUSE, texture2);
    // modelList[2]->setTexture(0, MATERIAL_MAP_DIFFUSE, texture3);

    modelList[0]->setTransform().setScale(Vector3T<float>(0.1, 0.1, 0.1));
    // modelList[1]->setTransform().setScale(Vector3T<float>(0.1, 0.1, 0.1));
    // modelList[2]->setTransform().setScale(Vector3T<float>(0.1, 0.1, 0.1));

    modelList[0]->setTransform().setPosition(Vector3T<float>(80, 10, 140));
    // modelList[1]->setTransform().setPosition(Vector3T<float>(80, 10, 140));
    // modelList[2]->setTransform().setPosition(Vector3T<float>(80, 10, 140));

    modelList[0]->setTransform().setRotation(Vector3T<float>(180, 90, 0));
    // modelList[1]->setTransform().setRotation(Vector3T<float>(180, 90, 0));
    // modelList[2]->setTransform().setRotation(Vector3T<float>(180, 90, 0));

    std::vector<std::shared_ptr<gameEngine::encapsulation::BModel>> chooseUniverse =
    {
        modelList[0],
        // modelList[1],
        // modelList[2],
        // std::make_shared<IMAGE>(PIRATE_UNIVERSE, "Pirates"),
        // std::make_shared<IMAGE>(VIKING_UNIVERSE, "Vikings"),
        // std::make_shared<IMAGE>(SAMOURAI_UNIVERSE, "Samurai"),

    };
    _universeSelector =
    std::make_unique<gameEngine::component::TSelector<gameEngine::encapsulation::BModel>>("Choose an universe", chooseUniverse, Vector<float>(pos._x * 2.0, pos._y * 0.9), Vector<float>(size._x * 0.95, size._y * 1), 20, DARKGRAY, WHITE, true);
}

void EmptyScene::update()
{
    if (!_windowManager->isRunning()) {
        _info->setQuit(true);
    }
    _universeSelector->update();
}

void EmptyScene::draw()
{
    _universeSelector->draw();
}
