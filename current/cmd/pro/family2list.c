
#define LIST_LOG        "list.txt"

// �����������
int main( object me, string arg )
{
        int level, i, j, size;

        if( is_player(me) ) 
        {
                notify( "��û���㹻��Ȩ�ޡ�" );
		return 1;
        }

        for( i = 0; i <= 7; i ++ )
        {
                log_file( LIST_LOG, sprintf( "\n�ȼ�  �ȣ�  �ͣ�  ����  ����  ����  ����  ����  (�� %d ת)  ", me->get_reincarnation() ) );

                switch( i )
                {
              default : level = 1;  log_file( LIST_LOG, "������\n" );  break;
               case 1 : level = 30;  log_file( LIST_LOG, "�һ�Դ\n" );  break;
               case 2 : level = 30;  log_file( LIST_LOG, "��ɽ\n" );  break;
               case 3 : level = 30;  log_file( LIST_LOG, "������\n" );  break;
               case 4 : level = 30;  log_file( LIST_LOG, "����\n" );  break;
               case 5 : level = 30;  log_file( LIST_LOG, "éɽ\n" );  break;
               case 6 : level = 30;  log_file( LIST_LOG, "����ɽ\n" );  break;
               case 7 : level = 30;  log_file( LIST_LOG, "������\n" );  break;
                }

                for( j = level; j <= 150; j ++ )
                {
                        reset_eval_cost();
                        "/cmd/pro/family"->main(me, sprintf("%d %d", i * 10, j) );    // i: �޻���; i * 10 ����
                        log_file( LIST_LOG, sprintf( "%d %d %d %d %d %d %d %d\n", 
                                j, me->get_max_hp(), me->get_max_mp(), me->get_ap(), me->get_dp(), me->get_cp(), me->get_pp(), me->get_sp() ) );
                }
        }

        tell_user( me, "��鿴 list.txt �ļ���" );

        return 1;
}
