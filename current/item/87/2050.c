
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit WAIST;

// ��������������
int get_family() { return 2; }

// ���������촦��
void create()
{
        set_name("��Х����");
        set_picid_1(8709);
        set_picid_2(8709);

        set_level(50);
        set_value(10000);
        set_max_lasting(9399);
        set("dp", 53);
        set("pp", 38);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "��Х����";
}
