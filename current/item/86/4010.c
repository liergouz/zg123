
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("ͭ����");
        set_picid_1(8608);
        set_picid_2(8608);

        set_level(10);
        set_value(1800);
        set_max_lasting(5199);
        set("cp", 0);
        set("pp", 12);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "ͭ����";
}
