
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 1; }

// ���������촦��
void create()
{
        set_name("ͭ����");
        set_picid_1(8608);
        set_picid_2(8608);

        set_level(10);
        set_value(1500);
        set_max_lasting(6399);
        set("cp", 0);
        set("pp", 10);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "ͭ����";
}
