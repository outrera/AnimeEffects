#ifndef GUI_TOOLWIDGET_H
#define GUI_TOOLWIDGET_H

#include <QWidget>
#include <QResizeEvent>
#include "util/Signaler.h"
#include "ctrl/Driver.h"
#include "ctrl/FFDParam.h"
#include "gui/GUIResourceSet.h"
#include "gui/MainDisplayMode.h"
#include "gui/MainViewSetting.h"
#include "gui/tool/tool_ViewPanel.h"
#include "gui/tool/tool_ModePanel.h"
#include "gui/tool/tool_SRTPanel.h"
#include "gui/tool/tool_FFDPanel.h"
#include "gui/tool/tool_BonePanel.h"
#include "gui/tool/tool_MeshPanel.h"

namespace gui
{

class ToolWidget : public QWidget
{
public:
    ToolWidget(QWidget* aParent, GUIResourceSet& aResources, const QSize& aSizeHint);

    void setDriver(ctrl::Driver* aDriver);

    util::Signaler<void()> onVisualUpdated;
    util::Signaler<void(ctrl::ToolType)> onToolChanged;
    util::Signaler<void(const MainViewSetting&)> onViewSettingChanged;

private:
    virtual QSize sizeHint() const { return mSizeHint; }
    virtual void resizeEvent(QResizeEvent* aEvent);

    void createViewPanel();
    void createModePanel();
    void setPanelActivity(bool aIsActive);
    void setButtonActivity(ctrl::ToolType aType, bool aIsActive);
    void updateGeometry();
    void onModePanelPushed(ctrl::ToolType, bool);
    void onParamUpdated(bool aLayoutChanged);

    GUIResourceSet& mResourceSet;
    const QSize mSizeHint;
    tool::ViewPanel* mViewPanel;
    tool::ModePanel* mModePanel;
    ctrl::Driver* mDriver;
    ctrl::ToolType mToolType;

    tool::SRTPanel* mSRTPanel;
    tool::FFDPanel* mFFDPanel;
    tool::BonePanel* mBonePanel;
    tool::MeshPanel* mMeshPanel;

    MainViewSetting mMainViewSetting;
};

} // namespace gui

#endif // GUI_TOOLWIDGET_H