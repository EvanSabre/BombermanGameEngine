/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** ICamera
*/

#ifndef ICAMERA_HPP_
#define ICAMERA_HPP_

namespace gameEngine
{
    namespace interfaces
    {
        class ICamera
        {
        public:
            virtual ~ICamera() = default;

            virtual void beginMode() const noexcept = 0;
            virtual void endMode() const noexcept = 0;
        };

    } // namespace interfaces

} // namespace gameEngine


#endif /* !ICAMERA_HPP_ */
