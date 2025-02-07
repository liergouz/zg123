
#include <equip.h>

#define LIST_LOG        "list.txt"

// �����������
int main( object me, string arg )
{
        mixed *dfile;
        mapping *quest;
        string *name, path, file;
        int i, j, size, total, flag;

        if( is_player(me) ) 
        {
                notify( "��û���㹻��Ȩ�ޡ�" );
		return 1;
        }

        if( !arg ) arg = "";

        if( arg == "emote" )
        {
                name = EMOTE_D->get_all_emote();

                for( i = 0, size = sizeof(name); i < size; i ++ )
                        log_file( LIST_LOG, sprintf("%s %s\n", name[i], EMOTE_D->get_emote_note( name[i] ) ) );

                return 1;
        }

        path = absolute_path(me, arg);    // ��ȡ����·��
        if( directory_exist(path) && path[<1] != '/' ) path += "/";

        dfile = get_dir(path, -1);    // ��ȡ�ļ��б�

        if( !( size = sizeof(dfile) ) )    // ·���Ϸ��ж�
        {
                if( path[<1] != '/' ) 
		{
                        notify( "�޷��ҵ�����ļ���" );
		        return 1;
		}
                if( directory_exist( path[ 1..<2 ] ) ) 
		{
                        notify( "���Ŀ¼û�ж�����" );
		        return 1;
                }
                else
		{
                        notify( "�޷��ҵ����Ŀ¼��" );
		        return 1;
		}
        }

        path = path[ 0 .. strchr( path, '/', -1 ) + 1 ];    // �������·��

        for( i = 0; i < size; i ++ )    // ������ʾ����
        {
                file = path + dfile[i][0];    // ȡ����·����

                if( directory_exist(file) || dfile[i][0] == "." || dfile[i][0] == ".." ) continue;

                if( strlen(file) > 2 && file[<2..<1] != ".c" ) continue;

                if( file->is_skill() )
                {
                        log_file( LIST_LOG, sprintf( "%s", file->get_desc() ) );
                        continue;
                }
                else if( file->get_perform_type() )
                {
                        log_file( LIST_LOG, sprintf( "����%s", file->get_desc(me) ) );
                        continue;
                }

                if( file->is_quest_list() )
                {
                        log_file( LIST_LOG, sprintf( "\n���� ���� (%s��)\n", dfile[i][0][0..<3] ) );

                        quest = file->get_quest_list();
                        total = sizeof(quest);

                        for( j = 0; j < total; j ++ )
                                log_file( LIST_LOG, sprintf("%s %d\n", quest[j]["name"], quest[j]["exp"] ) );

                        continue;
                }

                if( !file->is_item() && !file->is_npc() ) continue;

                if( file->get_equip_type() == ARMOR_TYPE )
                {
                        if( !flag )
                        {
                                log_file( LIST_LOG, "\n��� ���� �ر�ͼ ����ͼ ���� �Ա� �ȼ�\n" );
                                flag = 1;
                        }
                        log_file( LIST_LOG, sprintf("%s %s %d %d %s %d %d %s\n", dfile[i][0][0..<3],
                                file->get_name(), file->get_picid_1(), file->get_picid_2(), 
                                file->get_unit(), file->get_gender(), file->get_level(), file->get_desc() ) );
                }
                else if( file->is_equip() )
                {
                        if( !flag )
                        {
                                log_file( LIST_LOG, "\n��� ���� �ر�ͼ ����ͼ ���� �ȼ�\n" );
                                flag = 1;
                        }
                        log_file( LIST_LOG, sprintf("%s %s %d %d %s %d %s\n", dfile[i][0][0..<3],
                                file->get_name(), file->get_picid_1(), file->get_picid_2(), 
                                file->get_unit(), file->get_level(), file->get_desc() ) );
                }
                else if( file->is_item() )
                {
                        if( !flag )
                        {
                                log_file( LIST_LOG, "\n��� ���� �ر�ͼ ����ͼ ���� �۸�\n" );
                                flag = 1;
                        }
                        log_file( LIST_LOG, sprintf("%s %s %d %d %s %d %s\n", dfile[i][0][0..<3],
                                file->get_name(), file->get_picid_1(), file->get_picid_2(), 
                                file->get_unit(), file->get_value(), file->get_desc() ) );
                }
                else if( file->is_badman() )
                {
                        if( !flag )
                        {
                                log_file( LIST_LOG, "\n��� ���� ���� �Ա� ���� ���� ����\n" );
                                flag = 1;
                        }
                        log_file( LIST_LOG, sprintf("%s %s %s %s %d %d %d\n", dfile[i][0][0..<3],
                                file->get_name(), file->get("figure"), 
                                file->get_gender() == 1 ? "��" : "Ů",
                                file->get_walk_speed(), file->get_attack_speed(), file->get_weapon_code() ) );
                }
                else if( file->is_npc() )
                {
                        if( !flag )
                        {
                                log_file( LIST_LOG, "\n��� ���� ����\n" );
                                flag = 1;
                        }
                        log_file( LIST_LOG, sprintf("%s %s %s\n", dfile[i][0][0..<3],
                                file->get_name(), file->is_officer() ? "---" : "NPC" ) );
                }
        }

        tell_user( me, "��鿴 list.txt �ļ���" );

        return 1;       
}
