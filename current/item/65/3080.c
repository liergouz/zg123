
// �Զ����ɣ�/make/equip/60b

#include <equip.h>

inherit HEAD;

// ��������������
int get_family() { return 3; }

// ���������촦��
void create()
{
        set_name("����սñ");
        set_picid_1(6540);
        set_picid_2(6540);

        set_level(80);
        set_value(26000);
        set_max_lasting(13899);
        set("dp", 104);
        set("pp", 46);

        setup();

        set_gender(1);
        set_head_code(46);
}

// ��������ȡ����
string get_desc()
{
        return "����սñ";
}
