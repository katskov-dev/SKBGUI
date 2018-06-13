unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, FileUtil, Forms, Controls, Graphics, Dialogs, StdCtrls,
  ExtCtrls, Menus, ComCtrls;

type

  { TForm1 }

  TForm1 = class(TForm)
    Button1: TButton;
    CheckGroup1: TCheckGroup;
    CheckGroup2: TCheckGroup;
    CheckGroup3: TCheckGroup;
    CheckGroup4: TCheckGroup;
    GroupBox1: TGroupBox;
    GroupBox2: TGroupBox;
    GroupBox3: TGroupBox;
    GroupBox4: TGroupBox;
    GroupBox5: TGroupBox;
    LabeledEdit1: TLabeledEdit;
    MainMenu1: TMainMenu;
    MenuItem1: TMenuItem;
    MenuItem2: TMenuItem;
    MenuItem3: TMenuItem;
    MenuItem4: TMenuItem;
    procedure Button1Click(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure GroupBox2Click(Sender: TObject);
    procedure LabeledEdit1Change(Sender: TObject);
    procedure MenuItem2Click(Sender: TObject);
    procedure MenuItem3Click(Sender: TObject);
  private

  public
  base_dir, compName: string;
  work_dir, inc_dir, src_dir:string;
  error: boolean;
  function GetValue(varName: string): string;
  function RenderTemplate(template_str: string): string;
  procedure generate_base_h();
  procedure generate_comp_h();
  procedure generate_comp_cpp();
  procedure generate_comp_model_h();
  procedure generate_comp_model_cpp();
  procedure generate_comp_viewer_h();
  procedure generate_comp_viewer_cpp();
  procedure generate_comp_controller_h();
  procedure generate_comp_controller_cpp();
  end;

var
  Form1: TForm1;

implementation

{$R *.lfm}

{ TForm1 }

procedure TForm1.LabeledEdit1Change(Sender: TObject);
var
  s: string;
begin
  s := LabeledEdit1.Text;
  if (s = '')
  then Button1.Enabled:=false
  else Button1.Enabled:=true;
end;

procedure TForm1.MenuItem2Click(Sender: TObject);
begin
Close();
end;

procedure TForm1.MenuItem3Click(Sender: TObject);
var info: string;
begin
  info := 'Component Generator' + #13;
  info := info + 'Название: Генератор компонентов для SKBGUI' + #13;
  info := info + 'Версия: 0.1.7' + #13;
  info := info + 'Разработчик: СКБ ИТ' + #13;
  info := info + 'Забавно, но написано на Lazarus, т.к. пока библиотека еще сырая' + #13;
  ShowMessage(info);
end;

function TForm1.GetValue(varName: string): string;
begin
  if varName = 'COMP_NAME'
  then result := compName
  else result := 'Undefined';
end;

function TForm1.RenderTemplate(template_str: string): string;
var
  i, si, fi: integer;
  value, var_name: string;
begin
  i := Pos('$', template_str);
  while i <> 0 do
  begin
    si := i + 1;
    fi := si+1;
    while template_str[fi] <> ')' do fi := fi + 1;
    var_name := copy(template_str, si+1, fi-si-1);
    delete(template_str, i, fi-si+2);
    value := GetValue(var_name);
    Insert(value, template_str, i);
//    ShowMessage(var_name);
    i := Pos('$', template_str);
  end;
  result := template_str;
end;

procedure TForm1.generate_base_h();
var
  f: TextFile;
  s: string;
  ft: TextFile;
  sft: string;
begin
  AssignFile(f, work_dir+'base.h');
  AssignFile(ft, base_dir+'/templates/base.txt');
  Rewrite(f);
  reset(ft);
  while not EOF(ft) do
  begin
    readln(ft, s);
    s := RenderTemplate(s);
    writeln(f, RenderTemplate(s));
  end;
  closefile(ft);
  CloseFile(f);
end;

procedure TForm1.generate_comp_h();
var
  f: TextFile;
  s: string;
  ft: TextFile;
  sft: string;
begin
  AssignFile(f, inc_dir+compName+'.h');
  AssignFile(ft, base_dir+'/templates/comp_h.txt');
  Rewrite(f);
  reset(ft);
  while not EOF(ft) do
  begin
    readln(ft, s);
    s := RenderTemplate(s);
    writeln(f, RenderTemplate(s));
  end;
  closefile(ft);
  CloseFile(f);
end;

procedure TForm1.generate_comp_cpp();
var
  f: TextFile;
  s: string;
  ft: TextFile;
  sft: string;
begin
  AssignFile(f, src_dir+compName+'.cpp');
  AssignFile(ft, base_dir+'/templates/comp_cpp.txt');
  Rewrite(f);
  reset(ft);
  while not EOF(ft) do
  begin
    readln(ft, s);
    s := RenderTemplate(s);
    writeln(f, RenderTemplate(s));
  end;
  closefile(ft);
  CloseFile(f);
end;

procedure TForm1.generate_comp_model_h();
var
  f: TextFile;
  s: string;
  ft: TextFile;
  sft: string;
begin
  AssignFile(f, inc_dir+compName+'Model.h');
  AssignFile(ft, base_dir+'/templates/comp_model_h.txt');
  Rewrite(f);
  reset(ft);
  while not EOF(ft) do
  begin
    readln(ft, s);
    s := RenderTemplate(s);
    writeln(f, RenderTemplate(s));
  end;
  closefile(ft);
  CloseFile(f);
end;


procedure TForm1.generate_comp_model_cpp();
var
  f: TextFile;
  s: string;
  ft: TextFile;
  sft: string;
begin
  AssignFile(f, src_dir+compName+'Model.cpp');
  AssignFile(ft, base_dir+'/templates/comp_model_cpp.txt');
  Rewrite(f);
  reset(ft);
  while not EOF(ft) do
  begin
    readln(ft, s);
    s := RenderTemplate(s);
    writeln(f, RenderTemplate(s));
  end;
  closefile(ft);
  CloseFile(f);
end;

procedure TForm1.generate_comp_viewer_h();
var
  f: TextFile;
  s: string;
  ft: TextFile;
  sft: string;
begin
  AssignFile(f, inc_dir+compName+'Viewer.h');
  AssignFile(ft, base_dir+'/templates/comp_viewer_h.txt');
  Rewrite(f);
  reset(ft);
  while not EOF(ft) do
  begin
    readln(ft, s);
    s := RenderTemplate(s);
    writeln(f, RenderTemplate(s));
  end;
  closefile(ft);
  CloseFile(f);
end;

procedure TForm1.generate_comp_viewer_cpp();
var
  f: TextFile;
  s: string;
  ft: TextFile;
  sft: string;
begin
  AssignFile(f, src_dir+compName+'Viewer.cpp');
  AssignFile(ft, base_dir+'/templates/comp_viewer_cpp.txt');
  Rewrite(f);
  reset(ft);
  while not EOF(ft) do
  begin
    readln(ft, s);
    s := RenderTemplate(s);
    writeln(f, RenderTemplate(s));
  end;
  closefile(ft);
  CloseFile(f);
end;

procedure TForm1.generate_comp_controller_h();
var
  f: TextFile;
  s: string;
  ft: TextFile;
  sft: string;
begin
  AssignFile(f, inc_dir+compName+'Controller.h');
  AssignFile(ft, base_dir+'/templates/comp_controller_h.txt');
  Rewrite(f);
  reset(ft);
  while not EOF(ft) do
  begin
    readln(ft, s);
    s := RenderTemplate(s);
    writeln(f, RenderTemplate(s));
  end;
  closefile(ft);
  CloseFile(f);
end;

procedure TForm1.generate_comp_controller_cpp();
var
  f: TextFile;
  s: string;
  ft: TextFile;
  sft: string;
begin
  AssignFile(f, src_dir+compName+'Controller.cpp');
  AssignFile(ft, base_dir+'/templates/comp_controller_cpp.txt');
  Rewrite(f);
  reset(ft);
  while not EOF(ft) do
  begin
    readln(ft, s);
    s := RenderTemplate(s);
    writeln(f, RenderTemplate(s));
  end;
  closefile(ft);
  CloseFile(f);
end;

procedure TForm1.Button1Click(Sender: TObject);
begin
  base_dir := GetCurrentDir;
  compName:= LabeledEdit1.Text;
  work_dir := base_dir + '/' + compName + '/';
  inc_dir := work_dir + '/include/'+compName+'/';
  src_dir := work_dir + '/src/'+compName+'/';
  error := not CreateDir(work_dir);
  error := error or not ForceDirectories(inc_dir);
  error := error or not ForceDirectories(src_dir);

  if error
  then ShowMessage('Ошибка! Не удалось создать каталог с именем: ' + compName)
  else begin
            generate_base_h();
            generate_comp_model_h();
            generate_comp_model_cpp();
            generate_comp_viewer_h();
            generate_comp_viewer_cpp();
            generate_comp_controller_h();
            generate_comp_controller_cpp();
            generate_comp_h();
            generate_comp_cpp();
            ShowMessage('Шаблон компонента успешно сгенерирован');
       end;
end;

procedure TForm1.FormCreate(Sender: TObject);
var i: integer;
begin
  compName:= 'None';
  //main class
  for i := 0 to 4 do
  begin
    TCheckBox(CheckGroup4.Controls[i]).Checked:=true;
    TCheckBox(CheckGroup4.Controls[i]).Enabled:=false;
  end;
  // controller
  for i := 0 to 2 do
  begin
    TCheckBox(CheckGroup3.Controls[i]).Checked:=true;
    TCheckBox(CheckGroup3.Controls[i]).Enabled:=false;
  end;
  //Viewer
  TCheckBox(CheckGroup2.Controls[2]).Checked:=true;
  TCheckBox(CheckGroup2.Controls[2]).Enabled:=false;
  TCheckBox(CheckGroup2.Controls[3]).Checked:=true;
  TCheckBox(CheckGroup2.Controls[3]).Enabled:=false;
  TCheckBox(CheckGroup2.Controls[4]).Checked:=true;
  TCheckBox(CheckGroup2.Controls[4]).Enabled:=false;
  //Model
  TCheckBox(CheckGroup1.Controls[15]).Checked:=true;
  TCheckBox(CheckGroup1.Controls[15]).Enabled:=false;

end;

procedure TForm1.GroupBox2Click(Sender: TObject);
begin

end;

end.

