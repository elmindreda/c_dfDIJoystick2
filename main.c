
#include <rpc.h>
#include <initguid.h>
#include <dinput.h>

#include <stdio.h>
#include <stdlib.h>

#define ENTRY(x) { #x, x }

typedef struct
{
    const char* name;
    DWORD value;
} Entry;

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

        if (odf->dwType & DIDFT_AXIS || odf->dwType & DIDFT_POV)
        {
            int i;
            const Entry entries[] =
            {
                ENTRY(DIJOFS_X),
                ENTRY(DIJOFS_Y),
                ENTRY(DIJOFS_Z),
                ENTRY(DIJOFS_RX),
                ENTRY(DIJOFS_RY),
                ENTRY(DIJOFS_RZ),
                ENTRY(DIJOFS_SLIDER(0)),
                ENTRY(DIJOFS_SLIDER(1)),
                ENTRY(DIJOFS_POV(0)),
                ENTRY(DIJOFS_POV(1)),
                ENTRY(DIJOFS_POV(2)),
                ENTRY(DIJOFS_POV(3)),
                ENTRY(FIELD_OFFSET(DIJOYSTATE2,lVX)),
                ENTRY(FIELD_OFFSET(DIJOYSTATE2,lVY)),
                ENTRY(FIELD_OFFSET(DIJOYSTATE2,lVZ)),
                ENTRY(FIELD_OFFSET(DIJOYSTATE2,lVRx)),
                ENTRY(FIELD_OFFSET(DIJOYSTATE2,lVRy)),
                ENTRY(FIELD_OFFSET(DIJOYSTATE2,lVRz)),
                ENTRY(FIELD_OFFSET(DIJOYSTATE2,rglVSlider[0])),
                ENTRY(FIELD_OFFSET(DIJOYSTATE2,rglVSlider[1])),
                ENTRY(FIELD_OFFSET(DIJOYSTATE2,lAX)),
                ENTRY(FIELD_OFFSET(DIJOYSTATE2,lAY)),
                ENTRY(FIELD_OFFSET(DIJOYSTATE2,lAZ)),
                ENTRY(FIELD_OFFSET(DIJOYSTATE2,lARx)),
                ENTRY(FIELD_OFFSET(DIJOYSTATE2,lARy)),
                ENTRY(FIELD_OFFSET(DIJOYSTATE2,lARz)),
                ENTRY(FIELD_OFFSET(DIJOYSTATE2,rglASlider[0])),
                ENTRY(FIELD_OFFSET(DIJOYSTATE2,rglASlider[1])),
                ENTRY(FIELD_OFFSET(DIJOYSTATE2,lFX)),
                ENTRY(FIELD_OFFSET(DIJOYSTATE2,lFY)),
                ENTRY(FIELD_OFFSET(DIJOYSTATE2,lFZ)),
                ENTRY(FIELD_OFFSET(DIJOYSTATE2,lFRx)),
                ENTRY(FIELD_OFFSET(DIJOYSTATE2,lFRy)),
                ENTRY(FIELD_OFFSET(DIJOYSTATE2,lFRz)),
                ENTRY(FIELD_OFFSET(DIJOYSTATE2,rglFSlider[0])),
                ENTRY(FIELD_OFFSET(DIJOYSTATE2,rglFSlider[1]))
            };

            for (i = 0;  i < sizeof(entries) / sizeof(Entry);  i++)
            {
                if (odf->dwOfs == entries[i].value)
                {
                    printf("%s,", entries[i].name);
                    break;
                }
            }

            if (i == sizeof(entries) / sizeof(Entry))
                exit(EXIT_FAILURE);
        }
        else if (odf->dwType & DIDFT_BUTTON)
            printf("DIJOFS_BUTTON(%u),", odf->dwOfs - DIJOFS_BUTTON0);
        else
            exit(EXIT_FAILURE);

        {
            int i, first = 1;
            const Entry entries[] =
            {
                ENTRY(DIDFT_AXIS),
                ENTRY(DIDFT_BUTTON),
                ENTRY(DIDFT_POV),
                ENTRY(DIDFT_OPTIONAL),
                ENTRY(DIDFT_ANYINSTANCE)
            };

            for (i = 0;  i < sizeof(entries) / sizeof(Entry);  i++)
            {
                if ((odf->dwType & entries[i].value) == entries[i].value)
                {
                    if (!first)
                        printf("|");

                    printf("%s", entries[i].name);
                    first = 0;
                }
            }

            printf(",");
        }

        {
            int i, first = 1;
            const Entry entries[] =
            {
                ENTRY(DIDOI_ASPECTACCEL),
                ENTRY(DIDOI_ASPECTFORCE),
                ENTRY(DIDOI_ASPECTPOSITION),
                ENTRY(DIDOI_ASPECTVELOCITY)
            };

            for (i = 0;  i < sizeof(entries) / sizeof(Entry);  i++)
            {
                if ((odf->dwFlags & entries[i].value) == entries[i].value)
                {
                    if (!first)
                        printf("|");

                    printf("%s", entries[i].name);
                    first = 0;
                }
            }
        }

        printf(" },\n");
    }

    exit(EXIT_SUCCESS);
}

