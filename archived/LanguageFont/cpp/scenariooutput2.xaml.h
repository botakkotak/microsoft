// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved

//
// Scenario2Output.xaml.h
// Declaration of the Scenario2Output class
//

#pragma once

#include "pch.h"
#include "ScenarioOutput2.g.h"
#include "MainPage.g.h"

namespace SDKTemplate
{
    [Windows::Foundation::Metadata::WebHostHidden]
    public ref class ScenarioOutput2 sealed
    {
    public:
        ScenarioOutput2();

    protected:
        virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;
        virtual void OnNavigatedFrom(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;

    private:
        ~ScenarioOutput2();
        MainPage^ rootPage;
        void rootPage_InputFrameLoaded(Object^ sender, Object^ e);
        Windows::Foundation::EventRegistrationToken _frameLoadedToken;
    };
}
