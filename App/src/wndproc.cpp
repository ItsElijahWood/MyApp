#include "app.h"
#include "framework.h"
#include "resource.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam,
                         LPARAM lParam) {
  switch (message) {
    case WM_COMMAND: {
      int wmId = LOWORD(wParam);
      switch (wmId) {
        case IDM_ABOUT:
          DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
          break;
        case IDM_EXIT:
          DestroyWindow(hWnd);
          break;
        default:
          return DefWindowProc(hWnd, message, wParam, lParam);
      }
    } break;

    case WM_PAINT: {
      PAINTSTRUCT ps;
      HDC hdc = BeginPaint(hWnd, &ps);

      const wchar_t* text = L"EJ's App";
      TextOut(hdc, 50, 50, text, wcslen(text));

      EndPaint(hWnd, &ps);
    } break;

    case WM_DESTROY:
      PostQuitMessage(0);
      break;

    default:
      return DefWindowProc(hWnd, message, wParam, lParam);
  }

  return 0;
}

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
  UNREFERENCED_PARAMETER(lParam);
  switch (message) {
    case WM_INITDIALOG:
      return (INT_PTR)TRUE;

    case WM_COMMAND:
      if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) {
        EndDialog(hDlg, LOWORD(wParam));
        return (INT_PTR)TRUE;
      }
      break;
  }
  return (INT_PTR)FALSE;
}
