/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Character
*/

#include "Character.hpp"

using namespace game::objects;

Character::Character(
    const std::string &id,
    const std::string &name,
    const std::string &texturePath,
    const std::string &model,
    const std::string &animWalk,
    const std::string &animIdle,
    const Vector3T<float> &pos
    ) : gameEngine::objects::Moveable(id),
      _isMoving(false),
      _bombRef(id),
      _frameCounter(0),
      _hasDropped(false)
{
    _bombQueue.push_front(std::make_shared<game::objects::Bomb>(_bombRef));
    _texture = std::make_shared<gameEngine::encapsulation::BTexture2D>(texturePath);
    _model = std::make_shared<gameEngine::encapsulation::BModel>(model);
    _animWalk = std::make_shared<gameEngine::encapsulation::BModelAnimation>(animWalk);
    _animIdle = std::make_shared<gameEngine::encapsulation::BModelAnimation>(animIdle);
    _anim = std::make_shared<gameEngine::encapsulation::BModelAnimation>(animIdle);
    // _animation = std::make_shared<gameEngine::Animation>(model, animWalk, animIdle, texturePath);
    _model->setTexture(0, MATERIAL_MAP_DIFFUSE, *_texture);
    _model->setTransform().setScale({0.1, 0.1, 0.1});
    this->_name = name;
    this->setTransform().setPosition(pos);
    _state = ANIMIDLE;
}

Character::~Character()
{
}

//getter

void Character::setCurrentEvent(game::Event event) noexcept
{
    _currentEvent = event;
}

game::Event Character::getCurrentEvent() const noexcept
{
    return _currentEvent;
}


std::string Character::getName() const noexcept
{
    return this->_name;
}

size_t Character::getScore() const noexcept
{
    return this->_score;
}

int Character::getState() const noexcept
{
    return _state;
}

int Character::getLives() const noexcept
{
    return _lives;
}

int Character::getNbBomb() const noexcept
{
    return _nbBomb;
}

bool Character::hasDropped() const noexcept
{
    return _hasDropped;
}

//setter

void Character::setIsMoving(bool isMoving) noexcept
{
    _isMoving = isMoving;
}

void Character::setCollider() noexcept
{
    Vector3T<float> pos(this->getTransform().getPosition());
    Vector3T<float> sca(this->getTransform().getScale());

    _collider.getBoundingBox().setBoundingBox(
        {(float)(pos._x - sca._x * (float)TILESIZE * 0.5),
        pos._y,
        (float)(pos._z - sca._z * (float)TILESIZE * 0.5)},
        {(float)(pos._x + sca._x * (float)TILESIZE * 0.5),
        pos._y,
        (float)(pos._z + sca._z * (float)TILESIZE * 0.5)});
}

void Character::setState(const int &state) noexcept
{
    _state = state;
}

void Character::addScore(const size_t value) noexcept
{
    this->_score += value;
}

void Character::subScore(const size_t value) noexcept
{
    this->_score -= value;
}

void Character::setModel(std::shared_ptr<gameEngine::encapsulation::BModel> model) noexcept
{
    this->_model = model;
}

void Character::setDropped(bool state) noexcept
{
    _hasDropped = state;
}

void Character::draw() const noexcept
{
    if (!this->_model)
        return;
    _model->setTransform().setPosition(this->_transform.getPosition());
    _model->setTransform().setRotation(this->_transform.getRotation());
    _model->setTransform().setScale(this->_transform.getScale());
    _model->rotate();
    _model->draw();
}

void Character::onCollisionEnter(const AGameObject &collision)
{
    try
    {
        std::unique_ptr<game::interfaces::IEffect> efx = game::objects::EffectFactory::makeEffect(collision.getTag());
        addPowerUpEffec(efx.get());
        std::cout << "get Power Up" << std::endl;
        return;
    }
    catch(const std::exception& e)
    {
    }
}

void Character::onCollisionExit(const AGameObject &collision)
{
}

void Character::update()
{
    updateModelAnimation();
}

void Character::updateModelAnimation()
{
    if (_clock.getElapsedTime() >= 3 && _nbBomb < _maxBomb) {
        _nbBomb++;
        _bombQueue.push_front(std::make_shared<game::objects::Bomb>(_bombRef));
    }
    setCollider();
    _anim = _state ? _animWalk : _animIdle;
    if (_model->isLoad() && _anim->isLoad()) {
        _frameCounter++;
        UpdateModelAnimation(_model->getObj(), _anim->getModelAnimation()[0], _frameCounter);
    }
    if (_frameCounter >= _anim->getAnimFrameCount()) {
        _frameCounter = 0;
    }
}

void Character::addPowerUpEffec(const game::interfaces::IEffect *efx) noexcept
{
    _lives += efx->getLife();
    _health += efx->getHealth();
    _maxBomb += efx->getNbBomb();
    _bombRange += efx->getBlastPower();
    _speed = _speed + efx->getSpeed();
}

game::Tag_e Character::getTag() const noexcept
{
    return  game::Tag::CHARACTER;
}

void Character::stand(std::size_t tick)
{
    std::cout << "stand " << getTransform() << std::endl;
    //exit(0);
}

// BOMBS
std::shared_ptr<game::objects::AExplosif> Character::getNextBomb()
{
    return _bombQueue.front();
}

std::deque<std::shared_ptr<game::objects::AExplosif>> &Character::getBombQueue()
{
    return _bombQueue;
}

void Character::dropBomb(std::size_t tick) noexcept
{
    (void)tick;
    if (_nbBomb <= 0 || _hasDropped)
        return;
    Vector3T<float> bombPos({
        (float)((int)((this->getTransform().getPosition()._x + 3) / 10) * 10),
        this->getTransform().getPosition()._y,
        (float)((int)((this->getTransform().getPosition()._z + 3) / 10) * 10)
    });

    _nbBomb--;
    _hasDropped = true;
    _clock.restart();
    _bombQueue.front()->setTransform().setPosition(bombPos);
    _bombQueue.front()->drop();
    _bombQueue.pop_front();
    std::cout << "> BOMB DROPPED <" << std::endl;
    std::cout << this->getTransform() << std::endl;
    // if (_bombQueue.empty())
    //     _bombQueue.push_front(std::make_shared<game::objects::Bomb>(_bombRef));
}

void Character::handleEvent() noexcept
{
    bool flag = false;

    for (auto &[evt, action] : _key_event) {

        try {
            if (_currentEvent == evt) {
                playerKeyEvt my_action = action;
                CALL_MEMBER_FN((*this), my_action)(1);
                _currentEvent = NULL_EVENT;
                flag = true;
                _isMoving = true;
                std::cout << "Bot " << (_isMoving ? "moving" : "idle") << std::endl;
            }
        } catch (std::out_of_range &my_exception) {
        }
    }
    setState(!flag ? ANIMIDLE : ANIMWALK);
}