
// �Զ����ɣ�/make/std/makexy    // �����ײ㣬�Ѿ�ȡ��

// ������ˢ�ֵص��б�

string *PointTable = ({
%s
});

int sizeof_point = sizeof(PointTable);

// ��������ȡ�Ϸ�����
int get_xy_point( int flag )
{
        string point;
        int i, z, x, y;

        reset_eval_cost();

        for( i = 0; i < 100; i ++ )
        // while( 1 )
        {
                point = PointTable[ random(sizeof_point) ];
                if( sscanf(point, "%%d,%%d,%%d", z, x, y) != 3 ) continue;
                x += random(15) - 7;  y += random(15) - 7;  
                if( get_block(z, x, y) & flag ) continue;
//              if( get_jumpout(z, x, y) ) continue;
                return  z * 1000000 + x * 1000 + y;
        }
        return 0;
}
