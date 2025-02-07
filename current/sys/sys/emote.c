
#include <ansi.h>

#define EMOTE           INI_DIR "emote.ini"

private mapping Emote = ([ ]);

private void load_emote();

// ���������ɶ�������
void SAVE_BINARY() { }

// ���������촦��
private void create() { load_emote(); }

// ��������ȡ��������
private void load_emote()
{
        string *line, lemma, content, verb;
        int i, size;

        // ������������
        line = explode( read_file( EMOTE ), "\n" );

        // ���鶯������
        size = sizeof(line);
        for( i = 0, verb = ""; i < size; i ++ ) 
        {
                if( line[i][0] == '#' || line[i] == "" ) continue;
                if( line[i][<1] <= ' ' ) line[i] = line[i][0..<2];    // UNIX ��ʽ
                if( line[i][0] == '#' || line[i] == "" ) continue;
                if( !sscanf( line[i], "%s : %s", lemma, content ) ) 
                {
                        log_file( ERROR, sprintf( "����: " EMOTE " �� %d �ж��������\n", i + 1 ) );
                        continue;
                }
                if( lemma == "ACT" ) 
                {
                        verb = content;
                        Emote[verb] = ([ ]);
                        Emote[verb]["none"] = "";
                        Emote[verb]["who"] = "";
                        Emote[verb]["self"] = "";
                        Emote[verb]["note"] = "";
                }
                else if( verb != "" ) switch( lemma ) 
                {
           case "ALL" : Emote[verb]["none"] = content;  break;
           case "WHO" : Emote[verb]["who"] = content;  break;
           case ">ME" : Emote[verb]["self"] = content;  break;
          case "NOTE" : Emote[verb]["note"] = content;  break;
                }
        }
}

// ��������ѯ���ж���
string *get_all_emote() { return sort_array( keys(Emote), 1 ); }

// ��������ѯ��������
mapping get_emote( string verb ) { return undefinedp( Emote[verb] ) ? ([ ]) : Emote[verb]; }

// ��������ѯ����˵��
string get_emote_note( string verb ) { return undefinedp( Emote[verb] ) ? "" : Emote[verb]["note"]; }

// -------------------------------------------------------------

// �����������Լ����
string get_self_respect( object me )    // (ү), 
{
        switch( me->get_gender() )
        {
      default : return "������";
       case 1 : switch( me->get_fam_name() )
                {
              default : return "����ү";
        case "�һ�Դ" : return "��ǰ��";
          case "��ɽ" : return "������";
        case "������" : return "������";
          case "����" : return "������";
          case "éɽ" : return "������";    // ����
        case "����ɽ" : return "���ɳ�";    // ����
        case "������" : return "����ʦ";
                }
       case 2 : switch( me->get_fam_name() )
                {
              default : return "������";
        case "�һ�Դ" : return "������";
          case "��ɽ" : return "��Ů��";
        case "������" : return "Ů������";
          case "����" : return "��Ů��";
          case "éɽ" : return "������";
        case "����ɽ" : return "���ɹ�";
        case "������" : return "Ů��ʦ��";
                }
        }
}

// ���������ضԷ����
string get_respect( object who )    // (��), ��λ(��), 
{
        switch( who->get_gender() )
        {
      default : return "����";
       case 1 : switch( who->get_fam_name() )
                {
              default : return "��ү";
        case "�һ�Դ" : return "׳ʿ";
          case "��ɽ" : return "����";
        case "������" : return "����";
          case "����" : return "����";
          case "éɽ" : return "����";    // ����
        case "����ɽ" : return "�ɳ�";    // ����
        case "������" : return "��ʦ";
                }
       case 2 : switch( who->get_fam_name() )
                {
              default : return "����";
        case "�һ�Դ" : return "����";
          case "��ɽ" : return "Ů��";
        case "������" : return "Ů����";
          case "����" : return "Ů��";
          case "éɽ" : return "����";
        case "����ɽ" : return "�ɹ�";
        case "������" : return "Ů��ʦ";
                }
        }
}

// ���������ضԷ����
string get_disrespect( object who )    // (С��), ����(С��), 
{
        switch( who->get_gender() )
        {
      default : return "��̫��";
       case 1 : switch( who->get_fam_name() )
                {
              default : return "���˵�";
        case "�һ�Դ" : return "���˵�";
          case "��ɽ" : return "������";
        case "������" : return "������";
          case "����" : return "������";
          case "éɽ" : return "������";    // ��ţ����, ������
        case "����ɽ" : return "������";
        case "������" : return "��ƥ��";
                }
       case 2 : switch( who->get_fam_name() )
                {
              default : return "������";
        case "�һ�Դ" : return "������";
          case "��ɽ" : return "������";
        case "������" : return "������";
          case "����" : return "������";
          case "éɽ" : return "����Ů";
        case "����ɽ" : return "������";
        case "������" : return "������";
                }
        }
}

// ������������鶯��
string do_emote( object me, string name, string verb, object who )
{
        string result;

        // ��ֹ�Ƿ�����
        if( !verb || !mapp(Emote) || undefinedp( Emote[verb] ) ) return 0;

        // �ж϶�������
        if( !objectp(who) )
        {
                if( !stringp( result = Emote[verb]["none"] ) ) return 0;
                result = replace_string(result, "(��)", HIC+name+NOR );
                result = replace_string(result, "(ү)", get_self_respect(me) );
        }
        else 
        {
                if( me == who )
                {
                        if( !stringp( result = Emote[verb]["self"] ) ) return 0;
                        result = replace_string(result, "(��)", HIC+name+NOR );
                        result = replace_string(result, "(ү)", get_self_respect(me) );
                }
                else
                {
                        if( !stringp( result = Emote[verb]["who"] ) ) return 0;
                        result = replace_string(result, "(��)", HIC+name+NOR );
                        result = replace_string(result, "(ү)", get_self_respect(me) );
                        result = replace_string(result, "(��)", HIC+ who->get_name() + NOR );
                        result = replace_string(result, "(��)", get_respect(who) );
                        result = replace_string(result, "(С��)", get_disrespect(who) );
                }
        }

        return result;
}
