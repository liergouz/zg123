
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit BOOTS;

// ��������������
int get_family() { return 8; }

// ���������촦��
void create()
{
        set_name("�鲼Ь");
        set_picid_1(8800);
        set_picid_2(8800);

        set_level(15);
        set_value(1850);
        set_max_lasting(5199);
        set("dp", 5);
        set("sp", 6);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "�鲼Ь";
}
