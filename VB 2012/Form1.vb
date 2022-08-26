Public Class Form1

    'VERSION REFERENCE
    '+ (0.0.0.1): Small code modifications
    '+ (0.0.1.0): Big code modifications
    '+ (0.1.0.0): Design modifications
    '+ (1.0.0.0): Program remake

    Dim Loader As IO.StreamReader

    Private Declare Function GetAsyncKeyState Lib "user32" (ByVal vKey As Integer) As Short

    Public Declare Sub mouse_event Lib "user32" Alias "mouse_event" (ByVal dwFlags As Integer, ByVal dx As Integer, ByVal dy As Integer, ByVal cButtons As Integer, ByVal dwExtraInfo As Integer)
    Public Const MOUSEEVENTF_LEFTDOWN = &H2 ' left button down
    Public Const MOUSEEVENTF_LEFTUP = &H4 ' left button up
    Public Const MOUSEEVENTF_MIDDLEDOWN = &H20 ' middle button down
    Public Const MOUSEEVENTF_MIDDLEUP = &H40 ' middle button up
    Public Const MOUSEEVENTF_RIGHTDOWN = &H8 ' right button down
    Public Const MOUSEEVENTF_RIGHTUP = &H10 ' right button up

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        Try
            My.Computer.FileSystem.CreateDirectory("C:\Dugun")
        Catch ex As Exception
        End Try
    End Sub

    Private Sub Timer1_Tick(sender As Object, e As EventArgs) Handles Timer1.Tick

        'HOTKEYS
        If (GetAsyncKeyState(17)) Then
            If (GetAsyncKeyState(81)) Then 'Q: STOP ALL
                Timer2.Stop()
                Timer3.Stop()
                Timer4.Stop()
            ElseIf (GetAsyncKeyState(87)) Then 'W: START AUTOCLICKER
                If CheckBox1.Checked = True Then
                    Label3.Text = NumericUpDown8.Value * 60
                    Timer5.Start()
                End If
                Timer3.Stop()
                Timer4.Stop()
                Dim Random_new As Random
                Random_new = New Random
                Dim Random_value As Integer = Random_new.Next(0, NumericUpDown5.Value)
                Timer2.Interval = NumericUpDown4.Value + Random_value
                Timer2.Start()
            ElseIf (GetAsyncKeyState(84)) Then 'T: START AUTOTYPER
                If CheckBox5.Checked = True Then
                    Label3.Text = NumericUpDown11.Value * 60
                    Timer5.Start()
                End If
                Timer2.Stop()
                Timer4.Stop()
                Dim Random_new As Random
                Random_new = New Random
                Dim Random_value As Integer = Random_new.Next(0, NumericUpDown10.Value)
                Timer3.Interval = NumericUpDown9.Value + Random_value
                Timer3.Start()
            ElseIf (GetAsyncKeyState(82)) Then 'R: START RECORDER
                Timer2.Stop()
                Timer3.Stop()
                ListBox1.Items.Clear()
                ListBox2.Items.Clear()
                ListBox3.Items.Clear()
                Timer4.Interval = NumericUpDown2.Value
                Timer4.Start()
            ElseIf (GetAsyncKeyState(69)) Then 'E: NOTE DOWN POSITION (COORDINATES)
                TextBox1.Text = Label7.Text
                TextBox2.Text = Label8.Text
            ElseIf (GetAsyncKeyState(89)) Then 'Y: NOTE DOWN POSITION (ADD TO TEXT)
                TextBox3.Text = TextBox3.Text + " (x,y) = (" + Label7.Text + "," + Label8.Text + ")"
            End If
        End If

        'STATUS GROUPBOX
        If Timer2.Enabled = True Then
            Label1.ForeColor = Color.Green
            Label1.Text = "Auto Clicker on"
        ElseIf Timer3.Enabled = True Then
            Label1.ForeColor = Color.Blue
            Label1.Text = "Auto Typer on"
        ElseIf Timer4.Enabled = True Then
            Label1.ForeColor = Color.Yellow
            Label1.Text = "Recorder on"
        Else
            Label1.ForeColor = Color.Red
            Label1.Text = "Stopped"
        End If

        If GetAsyncKeyState(Keys.LButton) Then
            Label5.Text = "Left"
        ElseIf GetAsyncKeyState(Keys.RButton) Then
            Label5.Text = "Right"
        ElseIf GetAsyncKeyState(Keys.MButton) Then
            Label5.Text = "Middle"
        Else
            Label5.Text = "None"
        End If

        Dim x_mouse_coordinate As Integer = Form1.MousePosition.X
        Dim y_mouse_coordinate As Integer = Form1.MousePosition.Y
        Label7.Text = x_mouse_coordinate
        Label8.Text = y_mouse_coordinate

        'MOUSE PATTERN INDEX
        If NumericUpDown1.Value > 0 And NumericUpDown1.Value < ListBox1.Items.Count Or NumericUpDown1.Value = ListBox1.Items.Count Then
            ListBox1.SelectedIndex = NumericUpDown1.Value - 1
            ListBox2.SelectedIndex = NumericUpDown1.Value - 1
            ListBox3.SelectedIndex = NumericUpDown1.Value - 1
        End If

        'STAGE ROW
        If Not ListBox1.Items.Count = 0 Then
            NumericUpDown1.Minimum = 1
            NumericUpDown1.Maximum = ListBox1.Items.Count
        Else
            NumericUpDown1.Minimum = 1
            NumericUpDown1.Maximum = 999999999999999999
        End If

        'RANDOM GAP Y
        Dim Random_new_y As Random
        Random_new_y = New Random
        Dim Random_value_y As Integer = Random_new_y.Next(-NumericUpDown3.Value, NumericUpDown3.Value)
        Form2.NumericUpDown1.Value = Random_value_y

    End Sub

    Private Sub Timer2_Tick(sender As Object, e As EventArgs) Handles Timer2.Tick
        'GO TO POSITION
        Dim Random_new_x As Random
        Random_new_x = New Random
        Dim Random_value_x As Integer = Random_new_x.Next(-NumericUpDown3.Value, NumericUpDown3.Value)
        Me.Cursor = New Cursor(Cursor.Current.Handle)
        Cursor.Position = New Point(ListBox2.SelectedItem + Random_value_x, ListBox3.SelectedItem + Form2.NumericUpDown1.Value)

        'CLICK
        If ListBox1.SelectedItem = "Left" Then
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0)
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0)
        ElseIf ListBox1.SelectedItem = "Middle" Then
            mouse_event(MOUSEEVENTF_MIDDLEDOWN, 0, 0, 0, 0)
            mouse_event(MOUSEEVENTF_MIDDLEUP, 0, 0, 0, 0)
        ElseIf ListBox1.SelectedItem = "Right" Then
            mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0)
            mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0)
        End If

        'NEXT STAGE
        If ListBox1.SelectedIndex = ListBox1.Items.Count - 1 Then
            If CheckBox2.Checked = True Then
                Dim Random_new_reloop As Random
                Random_new_reloop = New Random
                Dim Random_value_reloop As Integer = Random_new_reloop.Next(0, NumericUpDown7.Value)

                Dim Random_new_stage As Random
                Random_new_stage = New Random
                Dim Random_value_stage As Integer = Random_new_stage.Next(0, NumericUpDown5.Value)

                Timer2.Interval = NumericUpDown4.Value + Random_value_stage + Random_value_reloop
                NumericUpDown1.Value = 1
            Else
                Timer2.Stop()
            End If
        Else
            Dim Random_new_stage As Random
            Random_new_stage = New Random
            Dim Random_value_stage As Integer = Random_new_stage.Next(0, NumericUpDown5.Value)
            Timer2.Interval = NumericUpDown4.Value + Random_value_stage
            NumericUpDown1.Value = NumericUpDown1.Value + 1
        End If

    End Sub

    Private Sub Timer3_Tick(sender As Object, e As EventArgs) Handles Timer3.Tick

        'TYPE
        If CheckBox3.Checked = True Then
            If CheckBox4.Checked = True Then
                If RadioButton1.Checked = True Then

                    Dim Random_new_CB2 As Random
                    Random_new_CB2 = New Random
                    Dim Random_value_CB2 As Integer = Random_new_CB2.Next(1, ComboBox2.Items.Count)
                    ComboBox2.SelectedIndex = Random_value_CB2

                    Dim Random_new_CB3 As Random
                    Random_new_CB3 = New Random
                    Dim Random_value_CB3 As Integer = Random_new_CB3.Next(1, ComboBox3.Items.Count)
                    ComboBox3.SelectedIndex = Random_value_CB3

                    SendKeys.Send(ComboBox2.Text & ComboBox3.Text & TextBox3.Text & "{ENTER}")
                End If
                If RadioButton2.Checked = True Then
                    Dim Random_new_CB4 As Random
                    Random_new_CB4 = New Random
                    Dim Random_value_CB4 As Integer = Random_new_CB4.Next(1, ComboBox4.Items.Count)
                    ComboBox4.SelectedIndex = Random_value_CB4

                    SendKeys.Send(ComboBox4.Text & TextBox3.Text & "{ENTER}")
                End If
            Else
                If RadioButton1.Checked = True Then
                    SendKeys.Send(ComboBox2.Text & ComboBox3.Text & TextBox3.Text & "{ENTER}")
                End If
                If RadioButton2.Checked = True Then
                    SendKeys.Send(ComboBox4.Text & TextBox3.Text & "{ENTER}")
                End If
            End If
        Else
            SendKeys.Send(TextBox3.Text & "{ENTER}")
        End If

        'RANDOM
        Dim Random_new As Random
        Random_new = New Random
        Dim Random_value As Integer = Random_new.Next(0, NumericUpDown10.Value)
        Timer3.Interval = NumericUpDown9.Value + Random_value

    End Sub

    Private Sub Timer4_Tick(sender As Object, e As EventArgs) Handles Timer4.Tick
        If GetAsyncKeyState(Keys.LButton) Then
            ListBox1.Items.Add("Left")
        ElseIf GetAsyncKeyState(Keys.RButton) Then
            ListBox1.Items.Add("Right")
        ElseIf GetAsyncKeyState(Keys.MButton) Then
            ListBox1.Items.Add("Middle")
        Else
            ListBox1.Items.Add("None")
        End If

        Dim x_mouse_coordinate As Integer = Form1.MousePosition.X
        Dim y_mouse_coordinate As Integer = Form1.MousePosition.Y

        ListBox2.Items.Add(x_mouse_coordinate)
        ListBox3.Items.Add(y_mouse_coordinate)
    End Sub

    Private Sub Timer5_Tick(sender As Object, e As EventArgs) Handles Timer5.Tick
        If Timer2.Enabled = True Or Timer3.Enabled = True Then
            If Label3.Text = 0 Then
                Timer2.Stop()
                Timer3.Stop()
            Else
                Label3.Text = Label3.Text - 1
            End If
        Else
            Label3.Text = 0
            Timer5.Enabled = False
        End If
    End Sub

    Private Sub Button1_Click_1(sender As Object, e As EventArgs) Handles Button1.Click
        If Button1.Text = "English" Then
            GroupBox1.Text = Form2.TextBox1.Text
            GroupBox2.Text = Form2.TextBox3.Text
            GroupBox3.Text = Form2.TextBox5.Text
            GroupBox4.Text = Form2.TextBox7.Text
            GroupBox5.Text = Form2.TextBox9.Text
            GroupBox6.Text = Form2.TextBox11.Text
            GroupBox7.Text = Form2.TextBox7.Text
            GroupBox8.Text = Form2.TextBox13.Text

            Label2.Text = Form2.TextBox15.Text
            Label9.Text = Form2.TextBox17.Text
            Label11.Text = Form2.TextBox19.Text
            Label12.Text = Form2.TextBox21.Text
            Label13.Text = Form2.TextBox23.Text
            Label14.Text = Form2.TextBox25.Text
            Label15.Text = Form2.TextBox27.Text
            Label16.Text = Form2.TextBox29.Text
            Label17.Text = Form2.TextBox27.Text
            Label18.Text = Form2.TextBox31.Text
            Label19.Text = Form2.TextBox27.Text

            Button1.Text = Form2.TextBox33.Text
            Button2.Text = Form2.TextBox35.Text
            Button3.Text = Form2.TextBox37.Text
            Button4.Text = Form2.TextBox39.Text
            Button5.Text = Form2.TextBox41.Text
            Button6.Text = Form2.TextBox43.Text
            Button7.Text = Form2.TextBox45.Text
            Button8.Text = Form2.TextBox47.Text
            Button9.Text = Form2.TextBox49.Text
            Button10.Text = Form2.TextBox45.Text

            CheckBox1.Text = Form2.TextBox51.Text
            CheckBox2.Text = Form2.TextBox53.Text
            CheckBox3.Text = Form2.TextBox55.Text
            CheckBox4.Text = Form2.TextBox57.Text
            CheckBox5.Text = Form2.TextBox51.Text

            TextBox3.Text = Form2.TextBox59.Text

            RadioButton1.Text = Form2.TextBox61.Text
            RadioButton2.Text = Form2.TextBox63.Text

        Else
            GroupBox1.Text = Form2.TextBox2.Text
            GroupBox2.Text = Form2.TextBox4.Text
            GroupBox3.Text = Form2.TextBox6.Text
            GroupBox4.Text = Form2.TextBox8.Text
            GroupBox5.Text = Form2.TextBox10.Text
            GroupBox6.Text = Form2.TextBox12.Text
            GroupBox7.Text = Form2.TextBox8.Text
            GroupBox8.Text = Form2.TextBox14.Text

            Label2.Text = Form2.TextBox16.Text
            Label9.Text = Form2.TextBox18.Text
            Label11.Text = Form2.TextBox20.Text
            Label12.Text = Form2.TextBox22.Text
            Label13.Text = Form2.TextBox24.Text
            Label14.Text = Form2.TextBox26.Text
            Label15.Text = Form2.TextBox28.Text
            Label16.Text = Form2.TextBox30.Text
            Label17.Text = Form2.TextBox28.Text
            Label18.Text = Form2.TextBox32.Text
            Label19.Text = Form2.TextBox28.Text

            Button1.Text = Form2.TextBox34.Text
            Button2.Text = Form2.TextBox36.Text
            Button3.Text = Form2.TextBox38.Text
            Button4.Text = Form2.TextBox40.Text
            Button5.Text = Form2.TextBox42.Text
            Button6.Text = Form2.TextBox44.Text
            Button7.Text = Form2.TextBox46.Text
            Button8.Text = Form2.TextBox48.Text
            Button9.Text = Form2.TextBox50.Text
            Button10.Text = Form2.TextBox46.Text

            CheckBox1.Text = Form2.TextBox52.Text
            CheckBox2.Text = Form2.TextBox54.Text
            CheckBox3.Text = Form2.TextBox56.Text
            CheckBox4.Text = Form2.TextBox58.Text
            CheckBox5.Text = Form2.TextBox52.Text

            TextBox3.Text = Form2.TextBox60.Text

            RadioButton1.Text = Form2.TextBox62.Text
            RadioButton2.Text = Form2.TextBox64.Text

        End If
    End Sub

    Private Sub Button2_Click_1(sender As Object, e As EventArgs) Handles Button2.Click
        If Button1.Text = "Español" Then
            MsgBox(Form2.TextBox65.Text, MsgBoxStyle.Information, "Hotkeys")
        Else
            MsgBox(Form2.TextBox66.Text, MsgBoxStyle.Information, "Teclas de acceso rápido")
        End If
    End Sub

    Private Sub Button3_Click_1(sender As Object, e As EventArgs) Handles Button3.Click
        Process.Start("http://www.facebook.com/dugunautoclicker")
    End Sub

    Private Sub Button4_Click(sender As Object, e As EventArgs) Handles Button4.Click
        If Not (ComboBox1.SelectedItem = "" Or TextBox1.Text = "" Or TextBox2.Text = "") Then
            ListBox1.Items.Add(ComboBox1.SelectedItem)
            ListBox2.Items.Add(TextBox1.Text)
            ListBox3.Items.Add(TextBox2.Text)
        End If
    End Sub

    Private Sub Button5_Click(sender As Object, e As EventArgs) Handles Button5.Click
        If Not (ListBox1.Items.Count = 0 Or ComboBox1.SelectedItem = "" Or TextBox1.Text = "" Or TextBox2.Text = "") Then
            ListBox1.Items.Insert(ListBox1.SelectedIndex, ComboBox1.SelectedItem)
            ListBox2.Items.Insert(ListBox2.SelectedIndex, TextBox1.Text)
            ListBox3.Items.Insert(ListBox3.SelectedIndex, TextBox2.Text)
        End If
    End Sub

    Private Sub Button6_Click(sender As Object, e As EventArgs) Handles Button6.Click
        ListBox1.Items.Remove(ListBox1.SelectedItem)
        ListBox2.Items.Remove(ListBox2.SelectedItem)
        ListBox3.Items.Remove(ListBox3.SelectedItem)
    End Sub

    Private Sub Button7_Click(sender As Object, e As EventArgs) Handles Button7.Click
        ListBox1.Items.Clear()
        ListBox2.Items.Clear()
        ListBox3.Items.Clear()
    End Sub

    Private Sub Button8_Click(sender As Object, e As EventArgs) Handles Button8.Click
        Try
            FileOpen(1, "C:\Dugun\Click events.txt", OpenMode.Output)
            For i = 0 To ListBox1.Items.Count - 1
                PrintLine(1, ListBox1.Items(i))
            Next

            FileOpen(2, "C:\Dugun\X coordinates.txt", OpenMode.Output)
            For i = 0 To ListBox2.Items.Count - 1
                PrintLine(2, ListBox2.Items(i))
            Next

            FileOpen(3, "C:\Dugun\Y coordinates.txt", OpenMode.Output)
            For i = 0 To ListBox3.Items.Count - 1
                PrintLine(3, ListBox3.Items(i))
            Next
        Catch ex As Exception
        End Try

        Try
            FileClose(1, "C:\Dugun\Click events.txt")
            FileClose(2, "C:\Dugun\X coordinates.txt")
            FileClose(3, "C:\Dugun\Y coordinates.txt")
        Catch ex As Exception
        End Try
    End Sub

    Private Sub Button9_Click(sender As Object, e As EventArgs) Handles Button9.Click
        Try
            Timer1.Stop()

            Loader = IO.File.OpenText("C:\Dugun\Click events.txt")
            Dim loaded_click_events() As String = Loader.ReadToEnd.Split(vbNewLine)
            ListBox1.Items.AddRange(loaded_click_events)

            Loader = IO.File.OpenText("C:\Dugun\X coordinates.txt")
            Dim loaded_X_coordinates() As String = Loader.ReadToEnd.Split(vbNewLine)
            ListBox2.Items.AddRange(loaded_X_coordinates)

            Loader = IO.File.OpenText("C:\Dugun\Y coordinates.txt")
            Dim loaded_Y_coordinates() As String = Loader.ReadToEnd.Split(vbNewLine)
            ListBox3.Items.AddRange(loaded_Y_coordinates)

            ListBox1.SelectedIndex = ListBox1.Items.Count - 1
            ListBox2.SelectedIndex = ListBox2.Items.Count - 1
            ListBox3.SelectedIndex = ListBox3.Items.Count - 1

            ListBox1.Items.Remove(ListBox1.SelectedItem)
            ListBox2.Items.Remove(ListBox2.SelectedItem)
            ListBox3.Items.Remove(ListBox3.SelectedItem)

            ListBox1.SelectedIndex = 1
            ListBox2.SelectedIndex = 1
            ListBox3.SelectedIndex = 1

            Timer1.Start()
        Catch ex As Exception
        End Try

    End Sub

    Private Sub Button10_Click(sender As Object, e As EventArgs) Handles Button10.Click
        TextBox3.Clear()
    End Sub

End Class
