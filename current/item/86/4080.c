
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit NECK;

// ��������������
int get_family() { return 4; }

// ���������촦��
void create()
{
        set_name("�֮��");
        set_picid_1(8664);
        set_picid_2(8664);

        set_level(80);
        set_value(53750);
        set_max_lasting(7299);
        set("cp", 0);
        set("pp", 82);

        setup();
}

// ��������ȡ����
string get_desc()
{
        return "�֮��";
}
