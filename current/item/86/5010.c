
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 5; }

// ���������촦��
void create()
{
        set_name("ͭ����");
        set_picid_1(8608);
        set_picid_2(8608);

        set_level(10);
        set_value(2000);
        set_max_lasting(4699);
        set("cp", 8);
        set("pp", 16);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "ͭ����";
}
