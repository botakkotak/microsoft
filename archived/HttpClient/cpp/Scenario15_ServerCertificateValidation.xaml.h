//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// This code is licensed under the MIT License (MIT).
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
//*********************************************************


#pragma once

#include "pch.h"
#include "Scenario15_ServerCertificateValidation.g.h"
#include "MainPage.xaml.h"

namespace SDKTemplate
{
    ///// <summary>
    ///// An empty page that can be used on its own or navigated to within a Frame.
    ///// </summary>
    [Windows::Foundation::Metadata::WebHostHidden]
    public ref class Scenario15 sealed
    {
    public:
        Scenario15();

    protected:
        virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;
        virtual void OnNavigatedFrom(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e)override;

    private:
        MainPage^ rootPage;
        Windows::Web::Http::Filters::HttpBaseProtocolFilter^ filter;
        Windows::Web::Http::HttpClient^ httpClient;
        concurrency::cancellation_token_source cancellationTokenSource;

        void Start_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
        void Cancel_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);


        void MyCustomServerCertificateValidator(Windows::Web::Http::Filters::HttpBaseProtocolFilter^ sender, Windows::Web::Http::Filters::HttpServerCustomValidationRequestedEventArgs^ args);
        Concurrency::task<bool> IsCertificateValidAsync(Windows::Security::Cryptography::Certificates::Certificate^ serverCert);

        void DefaultOSValidation_Checked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
        void DefaultAndCustomValidation_Checked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
        void IgnoreErrorsAndCustomValidation_Checked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
    };
}