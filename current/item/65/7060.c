
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 7; }

// ���������촦��
void create()
{
        set_name("���ƹ�");
        set_picid_1(6558);
        set_picid_2(6558);

        set_level(60);
        set_value(23500);
        set_max_lasting(7299);
        set("dp", 43);
        set("pp", 67);

        setup();

        set_gender(1);
        set_head_code(44);
}

// ��������ȡ����
string get_desc()
{
        return "���ƹ�";
}
