//
// Created by LSTME on 2022-10-15.
//


#include <pch.hpp>
#include <animation.hpp>
#include <timer.hpp>
#include <private_helpers.hpp>

using namespace lstme;

Frame::Frame() {
}

Frame::Frame(int newIndex, double newTimeIntervalInSeconds)
  : index(newIndex)
  , timeIntervalInSeconds(newTimeIntervalInSeconds) {
}

double Frame::timeInSeconds() const {
  return index * timeIntervalInSeconds;
}

void Frame::advance() {
  ++index;
}

void Frame::advance(int delta) {
  index += delta;
}

Frame& Frame::operator++() {
  advance();
  return *this;
}

Frame Frame::operator++(int i) {
  UNUSED_VARIABLE(i);

  Frame result = *this;
  advance();
  return result;
}

Animation::Animation() {
}

Animation::~Animation() {
}

void Animation::update(const Frame& frame) {
  Timer timer;

  LSTME_INFO << "Begin updating frame: " << frame.index
             << " timeIntervalInSeconds: " << frame.timeIntervalInSeconds
             << " (1/" << 1.0 / frame.timeIntervalInSeconds
             << ") seconds";

  onUpdate(frame);

  LSTME_INFO << "End updating frame (took " << timer.durationInSeconds()
             << " seconds)";
}
