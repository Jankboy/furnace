/**
 * Furnace Tracker - multi-system chiptune tracker
 * Copyright (C) 2021-2022 tildearrow and contributors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "gui.h"
#include "guiConst.h"

// TODO: actually implement a piano!
void FurnaceGUI::drawPiano() {
  if (nextWindow==GUI_WINDOW_PIANO) {
    pianoOpen=true;
    ImGui::SetNextWindowFocus();
    nextWindow=GUI_WINDOW_NOTHING;
  }
  if (!pianoOpen) return;
  if (ImGui::Begin("Piano",&pianoOpen)) {
    for (int i=0; i<e->getTotalChannelCount(); i++) {
      DivChannelState* cs=e->getChanState(i);
      if (cs->keyOn) {
        const char* noteName=NULL;
        if (cs->note<-60 || cs->note>120) {
          noteName="???";
        } else {
          noteName=noteNames[cs->note+60];
        }
        ImGui::Text("%d: %s",i,noteName);
      }
    }
  }
  if (ImGui::IsWindowFocused(ImGuiFocusedFlags_ChildWindows)) curWindow=GUI_WINDOW_PIANO;
  ImGui::End();
}