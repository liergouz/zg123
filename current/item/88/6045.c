
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit BOOTS;

// ��������������
int get_family() { return 6; }

// ���������촦��
void create()
{
        set_name("��ͷЬ");
        set_picid_1(8805);
        set_picid_2(8805);

        set_level(45);
        set_value(9300);
        set_max_lasting(5899);
        set("dp", 11);
        set("sp", 17);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��ͷЬ";
}
