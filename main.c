
#include <rpc.h>
#include <initguid.h>
#include <dinput.h>

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    DWORD i;

    for (i = 0;  i < c_dfDIJoystick2.dwNumObjs;  i++)
    {
        DIOBJECTDATAFORMAT* odf = c_dfDIJoystick2.rgodf + i;

        printf("{ ");

        if (odf->pguid)
        {
            RPC_STATUS status;

            if (UuidCompare((UUID*) odf->pguid, (UUID*) &GUID_XAxis, &status) == 0)
                printf("&GUID_XAxis,");
            else if (UuidCompare((UUID*) odf->pguid, (UUID*) &GUID_YAxis, &status) == 0)
                printf("&GUID_YAxis,");
            else if (UuidCompare((UUID*) odf->pguid, (UUID*) &GUID_ZAxis, &status) == 0)
                printf("&GUID_ZAxis,");
            else if (UuidCompare((UUID*) odf->pguid, (UUID*) &GUID_RxAxis, &status) == 0)
                printf("&GUID_RxAxis,");
            else if (UuidCompare((UUID*) odf->pguid, (UUID*) &GUID_RyAxis, &status) == 0)
                printf("&GUID_RyAxis,");
            else if (UuidCompare((UUID*) odf->pguid, (UUID*) &GUID_RzAxis, &status) == 0)
                printf("&GUID_RzAxis,");
            else if (UuidCompare((UUID*) odf->pguid, (UUID*) &GUID_Slider, &status) == 0)
                printf("&GUID_Slider,");
            else if (UuidCompare((UUID*) odf->pguid, (UUID*) &GUID_Button, &status) == 0)
                printf("&GUID_Button,");
            else if (UuidCompare((UUID*) odf->pguid, (UUID*) &GUID_Key, &status) == 0)
                printf("&GUID_Key,");
            else if (UuidCompare((UUID*) odf->pguid, (UUID*) &GUID_POV, &status) == 0)
                printf("&GUID_POV,");
            else if (UuidCompare((UUID*) odf->pguid, (UUID*) &GUID_Unknown, &status) == 0)
                printf("&GUID_Unknown,");
            else
                exit(EXIT_FAILURE);
        }
        else
            printf("NULL,");

        if (odf->dwType & DIDFT_AXIS)
        {
            if (odf->dwOfs == DIJOFS_X)
                printf("DIJOFS_X,");
            else if (odf->dwOfs == DIJOFS_Y)
                printf("DIJOFS_Y,");
            else if (odf->dwOfs == DIJOFS_Z)
                printf("DIJOFS_Z,");
            else if (odf->dwOfs == DIJOFS_RX)
                printf("DIJOFS_RX,");
            else if (odf->dwOfs == DIJOFS_RY)
                printf("DIJOFS_RY,");
            else if (odf->dwOfs == DIJOFS_RZ)
                printf("DIJOFS_RZ,");
            else if (odf->dwOfs == DIJOFS_SLIDER(0))
                printf("DIJOFS_SLIDER(0),");
            else if (odf->dwOfs == DIJOFS_SLIDER(1))
                printf("DIJOFS_SLIDER(1),");
            else if (odf->dwOfs == FIELD_OFFSET(DIJOYSTATE2,lVX))
                printf("FIELD_OFFSET(DIJOYSTATE2,lVX),");
            else if (odf->dwOfs == FIELD_OFFSET(DIJOYSTATE2,lVY))
                printf("FIELD_OFFSET(DIJOYSTATE2,lVY),");
            else if (odf->dwOfs == FIELD_OFFSET(DIJOYSTATE2,lVZ))
                printf("FIELD_OFFSET(DIJOYSTATE2,lVZ),");
            else if (odf->dwOfs == FIELD_OFFSET(DIJOYSTATE2,lVRx))
                printf("FIELD_OFFSET(DIJOYSTATE2,lVRx),");
            else if (odf->dwOfs == FIELD_OFFSET(DIJOYSTATE2,lVRy))
                printf("FIELD_OFFSET(DIJOYSTATE2,lVRy),");
            else if (odf->dwOfs == FIELD_OFFSET(DIJOYSTATE2,lVRz))
                printf("FIELD_OFFSET(DIJOYSTATE2,lVRz),");
            else if (odf->dwOfs == FIELD_OFFSET(DIJOYSTATE2,rglVSlider[0]))
                printf("FIELD_OFFSET(DIJOYSTATE2,rglVSlider[0]),");
            else if (odf->dwOfs == FIELD_OFFSET(DIJOYSTATE2,rglVSlider[1]))
                printf("FIELD_OFFSET(DIJOYSTATE2,rglVSlider[1]),");
            else if (odf->dwOfs == FIELD_OFFSET(DIJOYSTATE2,lAX))
                printf("FIELD_OFFSET(DIJOYSTATE2,lAX),");
            else if (odf->dwOfs == FIELD_OFFSET(DIJOYSTATE2,lAY))
                printf("FIELD_OFFSET(DIJOYSTATE2,lAY),");
            else if (odf->dwOfs == FIELD_OFFSET(DIJOYSTATE2,lAZ))
                printf("FIELD_OFFSET(DIJOYSTATE2,lAZ),");
            else if (odf->dwOfs == FIELD_OFFSET(DIJOYSTATE2,lARx))
                printf("FIELD_OFFSET(DIJOYSTATE2,lARx),");
            else if (odf->dwOfs == FIELD_OFFSET(DIJOYSTATE2,lARy))
                printf("FIELD_OFFSET(DIJOYSTATE2,lARy),");
            else if (odf->dwOfs == FIELD_OFFSET(DIJOYSTATE2,lARz))
                printf("FIELD_OFFSET(DIJOYSTATE2,lARz),");
            else if (odf->dwOfs == FIELD_OFFSET(DIJOYSTATE2,rglASlider[0]))
                printf("FIELD_OFFSET(DIJOYSTATE2,rglASlider[0]),");
            else if (odf->dwOfs == FIELD_OFFSET(DIJOYSTATE2,rglASlider[1]))
                printf("FIELD_OFFSET(DIJOYSTATE2,rglASlider[1]),");
            else if (odf->dwOfs == FIELD_OFFSET(DIJOYSTATE2,lFX))
                printf("FIELD_OFFSET(DIJOYSTATE2,lFX),");
            else if (odf->dwOfs == FIELD_OFFSET(DIJOYSTATE2,lFY))
                printf("FIELD_OFFSET(DIJOYSTATE2,lFY),");
            else if (odf->dwOfs == FIELD_OFFSET(DIJOYSTATE2,lFZ))
                printf("FIELD_OFFSET(DIJOYSTATE2,lFZ),");
            else if (odf->dwOfs == FIELD_OFFSET(DIJOYSTATE2,lFRx))
                printf("FIELD_OFFSET(DIJOYSTATE2,lFRx),");
            else if (odf->dwOfs == FIELD_OFFSET(DIJOYSTATE2,lFRy))
                printf("FIELD_OFFSET(DIJOYSTATE2,lFRy),");
            else if (odf->dwOfs == FIELD_OFFSET(DIJOYSTATE2,lFRz))
                printf("FIELD_OFFSET(DIJOYSTATE2,lFRz),");
            else if (odf->dwOfs == FIELD_OFFSET(DIJOYSTATE2,rglFSlider[0]))
                printf("FIELD_OFFSET(DIJOYSTATE2,rglFSlider[0]),");
            else if (odf->dwOfs == FIELD_OFFSET(DIJOYSTATE2,rglFSlider[1]))
                printf("FIELD_OFFSET(DIJOYSTATE2,rglFSlider[1]),");
            else
                exit(EXIT_FAILURE);
        }
        else if (odf->dwType & DIDFT_POV)
        {
            if (odf->dwOfs == DIJOFS_POV(0))
                printf("DIJOFS_POV(0),");
            else if (odf->dwOfs == DIJOFS_POV(1))
                printf("DIJOFS_POV(1),");
            else if (odf->dwOfs == DIJOFS_POV(2))
                printf("DIJOFS_POV(2),");
            else if (odf->dwOfs == DIJOFS_POV(3))
                printf("DIJOFS_POV(3),");
            else
                exit(EXIT_FAILURE);
        }
        else if (odf->dwType & DIDFT_BUTTON)
        {
            printf("DIJOFS_BUTTON(%u),", odf->dwOfs - DIJOFS_BUTTON0);
        }
        else
            exit(EXIT_FAILURE);

        if (odf->dwType)
        {
            if ((odf->dwType & DIDFT_AXIS) == DIDFT_AXIS)
                printf("DIDFT_AXIS|");
            if ((odf->dwType & DIDFT_BUTTON) == DIDFT_BUTTON)
                printf("DIDFT_BUTTON|");
            if (odf->dwType & DIDFT_POV)
                printf("DIDFT_POV|");
            if (odf->dwType & DIDFT_OPTIONAL)
                printf("DIDFT_OPTIONAL|");
            if ((odf->dwType & DIDFT_ANYINSTANCE) == DIDFT_ANYINSTANCE)
                printf("DIDFT_ANYINSTANCE|");
        }

        printf("0,");

        if (odf->dwFlags)
        {
            if (odf->dwFlags & DIDOI_ASPECTACCEL)
                printf("DIDOI_ASPECTACCEL|");
            if (odf->dwFlags & DIDOI_ASPECTFORCE)
                printf("DIDOI_ASPECTFORCE|");
            if (odf->dwFlags & DIDOI_ASPECTPOSITION)
                printf("DIDOI_ASPECTPOSITION|");
            if (odf->dwFlags & DIDOI_ASPECTVELOCITY)
                printf("DIDOI_ASPECTVELOCITY|");
        }

        printf("0 },\n");
    }

    exit(EXIT_SUCCESS);
}

