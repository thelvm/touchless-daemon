#include <math.h>
#include "gestures.h"

hand_discrete::hand_discrete()
{
    handBits = {};
}

bool hand_discrete::operator==(const hand_discrete &rhs) const {
    return handBits == rhs.handBits;
}

bool hand_bitfield::operator==(const hand_bitfield &rhs) const {
    return l_hand_present == rhs.l_hand_present &&
           l_thumb == rhs.l_thumb &&
           l_index == rhs.l_index &&
           l_middle == rhs.l_middle &&
           l_ring == rhs.l_ring &&
           l_pinky == rhs.l_pinky &&
           l_roll == rhs.l_roll &&
           l_pitch == rhs.l_pitch &&
           l_yaw == rhs.l_yaw &&
           r_hand_present == rhs.r_hand_present &&
           r_thumb == rhs.r_thumb &&
           r_index == rhs.r_index &&
           r_middle == rhs.r_middle &&
           r_ring == rhs.r_ring &&
           r_pinky == rhs.r_pinky &&
           r_roll == rhs.r_roll &&
           r_pitch == rhs.r_pitch &&
           r_yaw == rhs.r_yaw;
}

bool hand_bitfield::operator!=(const hand_bitfield &rhs) const {
    return !(rhs == *this);
}

bool hand_discrete::operator!=(const hand_discrete &rhs) const {
    return !(rhs == *this);
}

unsigned int hand_discrete::get_l_hand_present() const {
    return handBits.l_hand_present;
}

void hand_discrete::set_l_hand_present(unsigned int x) {
    handBits.l_hand_present = x;
}

unsigned int hand_discrete::get_l_thumb() const {
    return handBits.l_thumb;
}

void hand_discrete::set_l_thumb(unsigned int x) {
    handBits.l_thumb = x;
}

unsigned int hand_discrete::get_l_index() const {
    return handBits.l_index;
}

void hand_discrete::set_l_index(unsigned int x) {
    handBits.l_index = x;
}

unsigned int hand_discrete::get_l_middle() const {
    return handBits.l_middle;
}

void hand_discrete::set_l_middle(unsigned int x) {
    handBits.l_middle = x;
}

unsigned int hand_discrete::get_l_ring() const {
    return handBits.l_ring;
}

void hand_discrete::set_l_ring(unsigned int x) {
    handBits.l_ring = x;
}

unsigned int hand_discrete::get_l_pinky() const {
    return handBits.l_pinky;
}

void hand_discrete::set_l_pinky(unsigned int x) {
    handBits.l_pinky = x;
}

unsigned int hand_discrete::get_l_roll() const {
    return handBits.l_roll;
}

void hand_discrete::set_l_roll(double roll) {
    handBits.l_roll = hand_discrete::discretize_angle(roll);
}

unsigned int hand_discrete::get_l_pitch() const {
    return handBits.l_pitch;
}

void hand_discrete::set_l_pitch(double pitch) {
    handBits.l_pitch = hand_discrete::discretize_angle(pitch);
}

unsigned int hand_discrete::get_l_yaw() const {
    return handBits.l_yaw;
}

void hand_discrete::set_l_yaw(double yaw) {
    handBits.l_yaw = hand_discrete::discretize_angle(yaw);
}

unsigned int hand_discrete::get_r_hand_present() const {
    return handBits.r_hand_present;
}

void hand_discrete::set_r_hand_present(unsigned int x) {
    handBits.r_hand_present = x;
}

unsigned int hand_discrete::get_r_thumb() const {
    return handBits.r_thumb;
}

void hand_discrete::set_r_thumb(unsigned int x) {
    handBits.r_thumb = x;
}

unsigned int hand_discrete::get_r_index() const {
    return handBits.r_index;
}

void hand_discrete::set_r_index(unsigned int x) {
    handBits.r_index = x;
}

unsigned int hand_discrete::get_r_middle() const {
    return handBits.r_middle;
}

void hand_discrete::set_r_middle(unsigned int x) {
    handBits.r_middle = x;
}

unsigned int hand_discrete::get_r_ring() const {
    return handBits.r_ring;
}

void hand_discrete::set_r_ring(unsigned int x) {
    handBits.r_ring = x;
}

unsigned int hand_discrete::get_r_pinky() const {
    return handBits.r_pinky;
}

void hand_discrete::set_r_pinky(unsigned int x) {
    handBits.r_pinky = x;
}

unsigned int hand_discrete::get_r_roll() const {
    return handBits.r_roll;
}

void hand_discrete::set_r_roll(double roll) {
    handBits.r_roll = hand_discrete::discretize_angle(roll);
}

unsigned int hand_discrete::get_r_pitch() const {
    return handBits.r_pitch;
}

void hand_discrete::set_r_pitch(double pitch) {
    handBits.r_pitch = hand_discrete::discretize_angle(pitch);
}

unsigned int hand_discrete::get_r_yaw() const {
    return handBits.r_yaw;
}

void hand_discrete::set_r_yaw(double yaw) {
    handBits.r_yaw = hand_discrete::discretize_angle(yaw);
}

unsigned int hand_discrete::discretize_angle(double angle) {
    return (unsigned int)round((( angle + M_PI ) / M_PI_4) - 4);
}


